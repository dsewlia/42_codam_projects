*This project has been created as part of the 42 curriculum by dsewlia.*

# Inception

## Description

Inception is a system administration and DevOps project focused on containerization using Docker.  
The goal is to set up a secure and modular infrastructure composed of multiple services running inside Docker containers and orchestrated with Docker Compose.

This project deploys:

- NGINX with TLS (HTTPS only)
- WordPress with PHP-FPM
- MariaDB database

Each service runs in its own container and communicates through a dedicated Docker network. Persistent data is managed through Docker volumes.

The infrastructure must be reproducible, isolated, and follow security best practices.

---

### Project Architecture

The stack includes:

- **NGINX** — Reverse proxy serving HTTPS traffic
- **WordPress** — Web application running via PHP-FPM
- **MariaDB** — Relational database storing WordPress data

All services are connected through a Docker bridge network and use Docker volumes for persistence.

---

### Design Choices

#### Virtual Machines vs Docker

| Virtual Machines   | Docker             |
|--------------------|--------------------|
| Emulates full OS   | Shares host kernel |
| Heavyweight        | Lightweight        |
| Slower startup     | Fast startup       |
| Larger disk usage  | Minimal disk usage |

A combination of Virtual Machine and Docker was chosen to comply with the project requirements and to achieve proper system isolation.

The Virtual Machine provides hardware-level isolation and guarantees a controlled environment independent from the host system.

Docker is used inside the Virtual Machine to containerize services, ensuring:

- Service isolation (Nginx, WordPress, MariaDB)
- Reproducibility of the infrastructure
- Easy deployment and teardown
- Resource efficiency compared to running services directly on the VM

Using both technologies together allows:
- Secure infrastructure separation from the host
- Controlled environment for evaluation
- Modular service architecture

---

#### Environment Variables vs Secrets

| Environment Variables (`.env` file)| Docker Secrets              |
|------------------------------------|-----------------------------|
| Stores non-sensitive configuration | Stores sensitive data       |
| Loaded at build/runtime            | Mounted securely at runtime |
| Visible inside container           | Not directly visible        |

Environment variables and Docker Secrets are both used to configure services, but they serve different purposes.

The `.env` file is used to store:

- Database name
- Hostname
- Domain name
- Service configuration variables

It simplifies configuration management and avoids hardcoding values inside Dockerfiles.

Docker Secrets are used to store sensitive information such as:

- Database root password
- Database user password

Secrets are mounted into containers at runtime.

#### Docker Network vs Host Network

| Docker Bridge Network         | Host Network        |
|-------------------------------|---------------------|
| Isolated containers           | Shares host network |
| Secure internal communication | Less isolation      |
| Explicit port exposure        | Direct host access  |

A bridge network is used to ensure service isolation and controlled communication.

---

#### Docker Volumes vs Bind Mounts

| Docker Volumes       | Bind Mounts            |
|----------------------|------------------------|
| Managed by Docker    | Direct host mapping    |
| Portable             | Machine dependent      |
| Safer for production | Easier for development |

Docker volumes are used to persist MariaDB and WordPress data safely.

---

## Instructions

### Requirements

- Docker
- Docker Compose
- Make

### Build and Run

```bash
make
```

### Stop Containers

```bash
make clean
```

### Full Cleanup (Containers, Images, Volumes, Data)

```bash
make fclean
```

---

## Resources

- Docker Official Documentation — https://docs.docker.com/
- Docker Compose Documentation — https://docs.docker.com/compose/
- NGINX Documentation — https://nginx.org/en/docs/
- MariaDB Documentation — https://mariadb.org/documentation/
- WordPress Documentation — https://wordpress.org/support/

### AI Usage Disclosure

AI tools were used during this project for:
- Clarifying Docker networking concepts
- Understanding volume persistence mechanisms
- Improving documentation structure
- Debugging configuration issues

All architecture decisions, configurations, and implementations were written and validated manually.

---

## License

This project is part of the 42 curriculum and is intended for educational purposes only.