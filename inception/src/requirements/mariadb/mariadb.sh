#!/bin/sh
set -e

MYSQL_ROOT_PASSWORD=$(cat /run/secrets/db_root_password)
MYSQL_PASSWORD=$(cat /run/secrets/db_password)

if [ -z "$MYSQL_ROOT_PASSWORD" ] || [ -z "$MYSQL_PASSWORD" ]; then
    echo "Error: secrets missing"
    exit 1
fi

# Initialize database if first start
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    echo "Initializing MariaDB..."

    mysql_install_db --user=mysql --datadir=/var/lib/mysql

    echo "Starting MariaDB temporarily..."
    mysqld --user=mysql --bind-address=0.0.0.0 &
    pid="$!"

    # Wait until server is ready
    until mysqladmin ping --silent; do
        sleep 2
    done

    echo "Configuring database..."

    mysql -u root <<EOF
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    mysqladmin -u root -p"${MYSQL_ROOT_PASSWORD}" shutdown
    wait "$pid"
fi

echo "Starting MariaDB..."
exec mysqld --user=mysql --bind-address=0.0.0.0
