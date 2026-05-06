#!/bin/sh
set -e

MYSQL_PASSWORD=$(cat /run/secrets/db_password)
WP_USER_PASSWORD=$(cat /run/secrets/wp_user_password)
WP_ADMIN_PASSWORD=$(cat /run/secrets/wp_admin_password)

if [ -z "$MYSQL_PASSWORD" ] || [ -z "$WP_USER_PASSWORD" ] || [ -z "$WP_ADMIN_PASSWORD" ]; then
    echo "DB secret missing"
    exit 1
fi

echo "Waiting for MariaDB server..."

until mysqladmin ping -h"$MYSQL_HOSTNAME" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" --silent; do
    sleep 2
done

echo "MariaDB is reachable, waiting for authentication..."

until mysql -h"$MYSQL_HOSTNAME" -u"$MYSQL_USER" -p"$MYSQL_PASSWORD" -e "SELECT 1" >/dev/null 2>&1
do
    sleep 2
done

echo "MariaDB authentication successful"

cd /var/www/html

# Download WordPress if not present
if [ ! -f wp-config.php ]; then

    echo "Downloading WordPress..."
    wp core download --allow-root

    echo "Creating wp-config..."
    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost="$MYSQL_HOSTNAME" \
        --allow-root

    echo "Installing WordPress..."

    wp core install \
        --url="https://${DOMAIN_NAME}" \
        --title="Inception" \
        --admin_user="$WP_ADMIN" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL" \
        --skip-email \
        --allow-root

    echo "Creating second user..."

    wp user create \
        "$WP_USER" \
        "$WP_USER_EMAIL" \
        --user_pass="$WP_USER_PASSWORD" \
        --role=author \
        --allow-root

	chown -R www-data:www-data /var/www/html

fi

exec "$@"