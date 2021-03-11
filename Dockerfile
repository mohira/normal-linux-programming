FROM ubuntu:20.04

WORKDIR /src

RUN apt update && \
    apt install -y build-essential

