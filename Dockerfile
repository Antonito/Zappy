# Use ubuntu image
FROM ubuntu

# Authors
MAINTAINER Arnaud Arthur <arthur.arnaud@epitech.eu>
MAINTAINER Bache Antoine <antoine.bache@epitech.eu>
MAINTAINER Khsime Marwane <marwane.khsime@epitech.eu>
MAINTAINER Petrenko Ludovic <ludovic.petrenko@epitech.eu>
MAINTAINER Troncy Lucas <lucas.troncy@epitech.eu>

# Install
RUN echo '[Installing basic packages]'
RUN apt-get update && apt-get -y upgrade
RUN apt-get install -y build-essential apt-utils software-properties-common curl sudo
RUN echo '[Installing npm]'
RUN apt-get install -y npm
RUN echo '[Installing nodejs]'
RUN curl -sL https://deb.nodesource.com/setup_8.x | sudo -E bash -
RUN apt-get install -y nodejs

# Create the project's folder in the container
RUN mkdir -p /home/Project

# Set environment variables.
ENV HOME /home/Zappy

# Copy the folder in the container
COPY . /home/Zappy

# Define working directory
WORKDIR /home/Zappy

# Successful Launch
RUN echo '[Containerization successful]'

# Define default command
CMD ["bash"]