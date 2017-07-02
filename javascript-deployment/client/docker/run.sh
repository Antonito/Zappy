sudo docker run --net="bridge" --name zappy-client-nginx -p 80:80 -d -v $PWD/..:/usr/share/nginx/html nginx
