# **************************************************************************** #
#                                INCEPTION                                    #
# **************************************************************************** #

COMPOSE_FILE = ./src/docker-compose.yml
DATA_PATH = ./data

# Default rule
all: up

# -----------------------------------------------------------------------------#
# Create required data directories (if not exist)
# -----------------------------------------------------------------------------#
data:
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	@echo "data valumes created"

# -----------------------------------------------------------------------------#
# Build images
# -----------------------------------------------------------------------------#
build: data
	@docker compose -f $(COMPOSE_FILE) build

# -----------------------------------------------------------------------------#
# Start containers
# -----------------------------------------------------------------------------#
up: build
	@docker compose -f $(COMPOSE_FILE) up -d

# -----------------------------------------------------------------------------#
# Stop containers
# -----------------------------------------------------------------------------#
down:
	@docker compose -f $(COMPOSE_FILE) down

# -----------------------------------------------------------------------------#
# Stop + remove containers + volumes
# -----------------------------------------------------------------------------#
clean:
	@docker compose -f $(COMPOSE_FILE) down -v

# -----------------------------------------------------------------------------#
# Remove everything (containers, volumes, images, data folders)
# -----------------------------------------------------------------------------#
fclean: clean
	@docker compose -f $(COMPOSE_FILE) down --rmi all
	@docker system prune -af
	@sudo rm -rf $(DATA_PATH)

# -----------------------------------------------------------------------------#
# Restart everything
# -----------------------------------------------------------------------------#
re: fclean all

# -----------------------------------------------------------------------------#
# Execute bash inside container
# Usage: make exec nginx
# -----------------------------------------------------------------------------#
exec:
	$(eval service=$(filter-out $@,$(MAKECMDGOALS)))
	@docker compose -f $(COMPOSE_FILE) exec $(service) bash

# -----------------------------------------------------------------------------#
# Show logs
# Usage: make logs wordpress
# -----------------------------------------------------------------------------#
logs:
	$(eval service=$(filter-out $@,$(MAKECMDGOALS)))
	@docker compose -f $(COMPOSE_FILE) logs -f $(service)

# -----------------------------------------------------------------------------#
# Helpers
# -----------------------------------------------------------------------------#
ps:
	@docker ps -a

images:
	@docker image ls

volumes:
	@docker volume ls

networks:
	@docker network ls

# Silence command echoing
.SILENT:

# Prevent make from treating extra words as targets
%:
	@: