#include <stdio.h>

int main(){
    char buf[4];
    fgets(buf, sizeof buf, stdin);

    printf("bufsize: %lu\n%s", sizeof buf, buf);
}