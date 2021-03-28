FROM ubuntu:20.04

WORKDIR /src

RUN apt update && \
    apt install -y build-essential && \
    apt install -y man && \
    yes | unminimize

RUN apt install -y less vim strace

RUN apt install -y python3
