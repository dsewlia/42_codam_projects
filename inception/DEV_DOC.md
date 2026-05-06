# DEVELOPER DOCUMENTATION

## Prerequisites

- Linux environment
- Docker installed
- Docker Compose installed
- Make utility

---

## Project Structure

```
inception/
├── Makefile
├── secrets
│   ├── db_password.txt
│   └── db_root_password.txt
│   └── wp_admin_password.txt
│   └── wp_user_password.txt
├── src
│   ├── .env
│   ├── docker-compose.yml
│   └── requirements
│       ├── mariadb
│       │   ├── Dockerfile
│       │   ├── mariadb.sh
│       │   └── mysqld.conf
│       ├── nginx
│       │   ├── Dockerfile
│       │   └── nginx.conf
│       └── wordpress
│           ├── Dockerfile
│           ├── wordpress.sh
│           └── www.conf
├── DEV_DOC.md
├── README.md
└── USER_DOC.md

```

---

## Environment Setup

1. Clone repository:

```bash
git clone <repository_url>
cd inception
```

2. Configure environment variables:

Create or edit `.env` file.

3. Ensure data directories exist:

```bash
mkdir -p data/mariadb data/wordpress
```

---

## Build and Launch

```bash
make
```

This runs:

```bash
docker compose up --build -d
```

---

## Managing Containers 

### Manually

1. Start Containers:

```bash
docker compose build
```

2. Stop containers:

```bash
docker compose down
```

3. Stop + remove comtainers + remove volumes:

```bash
docker compose down -v
```

4. Remove everything (containers, volumes, images, data folders)

```bash
docker compose down --rmi all
docker system prune -ad
rm -rf <data_path>
```

5. List containers:

```bash
docker ps -a
```

6. List networks:

```bash
docker network ls
```

7. List images:

```bash
docker image ls
```

8. List volumes:

```bash
docker volume ls
```

### Using Make

1. Start containers:

```bash
make up
```

2. Stop containers:
```bash
make down
```

3. Stop + remove comtainers + remove volumes:

```bash
make clean
```

4. Remove everything (containers, volumes, images, data folders)

```bash
make fclean
```

5. List containers:

```bash
make ps
```

6. List networks:

```bash
make networks
```

7. List images:

```bash
make images
```

8. List volumes:

```bash
make volumes
```

---

## Data Persistence

Project data is stored in Docker volumes:

- MariaDB database files
- WordPress uploaded content

Volumes ensure that data survives container recreation.

Data is located on the host machine in the directory defined in `docker-compose.yml`.

---

## Networking

Services communicate through a dedicated Docker bridge network.

- NGINX exposes port 443 to the host.
- WordPress and MariaDB communicate internally.

---

## Debugging Tips

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
make exec mariadb
mysql
USE `Wordpress`
```

---

## Rebuilding from Scratch

To fully reset project:

```bash
make fclean
make
```

This removes:
- Containers
- Images
- Volumes
- Local data directories