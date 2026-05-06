FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    php-fpm \
    php-mysql \
    php-gd \
    php-mbstring \
    mariadb-client \
    wget \
    curl \
    && rm -rf /var/lib/apt/lists/*

# Install WP-CLI
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY www.conf /etc/php/8.2/fpm/pool.d/www.conf

RUN mkdir -p /run/php

COPY wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/wordpress.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/usr/local/bin/wordpress.sh"]

CMD ["/usr/sbin/php-fpm8.2", "-F"]
