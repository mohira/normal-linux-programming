# 『ふつうのLinuxプログラミング』をやっていく会

メモはZennのスクラップに書いていく → https://zenn.dev/mohira/scraps/c1886a998ccd4f 

## Docker

```
$ docker build -t normal-linux:v1 .

$ docker run -it --rm --name tom --mount type=bind,source=`pwd`,destination=/src normal-linux:v1 /bin/bash
```

## docker-compose

```
$ docker-compose up --build
$ docker-compose run ubuntu

root@2d24480368bd:/src# gcc chap01/hello.c 
root@2d24480368bd:/src# ./a.out 
hello world
```