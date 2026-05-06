# USER DOCUMENTATION

## Overview of Services

This project provides the following services:

- NGINX (HTTPS reverse proxy)
- WordPress website
- MariaDB database

The services are containerized and communicate internally through Docker networking.

---

## Starting the Project

From the root directory:

```bash
make
```

This will:
- Build Docker images
- Create volumes
- Start containers

---

## Stopping the Project

To stop containers (but preserve the data):

```bash
make clean
```

To completely remove everything:

```bash
make fclean
```

---

## Accessing the Website

Open a browser and navigate to:

```
https://<your_login>.42.fr
```

Since a self-signed certificate is used, your browser may show a security warning.  
Accept the warning to proceed.

---

## Accessing the WordPress Admin Panel

Go to:

```
https://<your_login>.42.fr/wp-admin
```

Use the administrator credentials created during installation.

---

## Managing Credentials

Credentials are stored in:

- `.env` file (environment variables)
- `/secrets/*` directory (docker secrets)
- Docker Compose configuration

To change credentials:
1. Edit the `.env` file
2. Edit the files in `/secrets/` directory
3. Run:

```bash
make fclean
make
```

---

## Checking Services Status

List running containers:

```bash
make ps
```

Check container logs:

```bash
make logs <container_name>
```

Enter container shell:

```bash
make exec <container_name>
```

Check database manually:

```bash
docker exec -it mariadb mysql -u root -p
```


---

## Verifying Persistence

To verify data persistence:

1. Create a WordPress user.

2. Run:

```bash
make clean
make
```

3. Confirm that the user still exists.

```bash
make exec mariadb
mysql
USE `Wordpress`;
SELECT * FROM wp_users;
```

## Basic Tests

With containers running, you can run the tests below

### TLS/SSL

```bash
openssl s_client -connect localhost:443
# Look in the output for the line with “Protocol” followed by the type of protocol used
# If you try any other port, the output should be an error
```

### PORTS:

1. nginx connects to wordpress via port 9000

```bash
docker exec -it nginx nc -zv wordpress 9000
# [SUCCESS MESSAGE]: Connection to wordpress (xxx.x.x.x) 9000 port [tcp/*] succeeded!
# [ERROR MESSAGE]: OCI runtime exec failed: exec failed: unable to start container process: exec: "nc"...
# If the error occurs, it means netcat isn't installed in the Docker container. To resolve this, run:
docker exec -it nginx bash
apt-get update && apt-get install -y netcat-openbsd
exit
# Now, try the initial command again:
docker exec -it nginx nc -zv wordpress 9000
```

2. wordpress connects to mariadb via port 3306

```bash
docker exec -it wordpress nc -zv mariadb 3306
# [SUCCESS MESSAGE]: Connection to mariadb (xxx.x.x.x) 3306 port [tcp/mysql] succeeded!
# [ERROR MESSAGE]: OCI runtime exec failed: exec failed: unable to start container process: exec: "nc"...
# If the error occurs, it means netcat isn't installed in the Docker container. To resolve this, run:
docker exec -it wordpress bash
apt-get update && apt-get install -y netcat-openbsd
exit
# Now, try the initial command again:
docker exec -it wordpress nc -zv mariadb 3306
```

3. check mariadb databases

```bash
docker exec -it mariadb bash
mariadb
SHOW DATABASES;
USE <database_name>;
SHOW TABLES;
SELECT * FROM <table_name>;
```