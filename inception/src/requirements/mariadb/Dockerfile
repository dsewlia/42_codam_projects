FROM debian:bookworm

RUN apt-get update && apt-get install -y \
    mariadb-server \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/run/mysqld \
    && chown -R mysql:mysql /var/run/mysqld \
    && chown -R mysql:mysql /var/lib/mysql \
    && chmod 755 /var/run/mysqld

COPY mariadb.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/mariadb.sh
COPY mysqld.conf /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

ENTRYPOINT ["/usr/local/bin/mariadb.sh"]
