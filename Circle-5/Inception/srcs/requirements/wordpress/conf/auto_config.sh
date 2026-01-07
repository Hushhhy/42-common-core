#!/bin/sh

set -e

# Basic wait so MariaDB is ready
sleep 10

if [ ! -d "/run/php" ]; then
    mkdir -p /run/php
fi

cd /var/www/wordpress

if [ ! -f wp-config.php ]; then
    wp config create --allow-root \
        --dbname="$SQL_DATABASE" \
        --dbuser="$SQL_USER" \
        --dbpass="$SQL_PASSWORD" \
        --dbhost="mariadb:3306" \
        --path="/var/www/wordpress"
fi

if ! wp core is-installed --allow-root --path="/var/www/wordpress"; then
    wp core install --allow-root \
        --url="$WP_URL" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL"
fi

if [ -n "$WP_USER" ] && [ -n "$WP_USER_EMAIL" ] && [ -n "$WP_USER_PASSWORD" ]; then
    if ! wp user get "$WP_USER" --allow-root --path="/var/www/wordpress" >/dev/null 2>&1; then
        wp user create "$WP_USER" "$WP_USER_EMAIL" --user_pass="$WP_USER_PASSWORD" --allow-root --path="/var/www/wordpress"
    fi
fi

exec /usr/sbin/php-fpm7.3 -F