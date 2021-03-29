#include <stdio.h>
#include <stdlib.h>

void print_1バイトずつ(FILE *f);

int main() {
    char *filename = "hello.txt";
    FILE *f = fopen(filename, "r");

    if (!f) {
        perror(filename);
        exit(1);
    }

    print_1バイトずつ(f);

    fclose(f);

    // 標準入力でもおk
    // print_1バイトずつ(stdin);
}

void print_1バイトずつ(FILE *f) {
    int c;
    for (;;) {
        c = fgetc(f);
        if (c == EOF) {
            break;
        }
        printf("%d %c\n", c, c);

    }
}
