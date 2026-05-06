FROM debian:bookworm

# RUN apt-get update && apt-get install -y nginx
# RUN apt-get install -y openssl

ARG CRED_PATH CRED_CERT CRED_KEY DOMAIN_NAME
RUN apt update && apt upgrade -y && apt install -y nginx openssl gettext-base
RUN mkdir -p ${CRED_PATH}
RUN chown -R www-data:www-data /var/www/html

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
	-keyout ${CRED_PATH}/${CRED_KEY} \
	-out ${CRED_PATH}/${CRED_CERT} \
    -subj "/C=NL/ST=Amsterdam/L=Amsterdam/O=42Amsterdam/OU=Student/CN=dsewlia.42.fr"

COPY ./nginx.conf ./tmp/nginx.conf

RUN envsubst '$CRED_PATH $CRED_KEY $CRED_CERT $DOMAIN_NAME' < /tmp/nginx.conf > /etc/nginx/sites-available/default

EXPOSE 443

ENTRYPOINT ["nginx", "-g", "daemon off;"]