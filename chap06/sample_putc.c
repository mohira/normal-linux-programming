#include <stdio.h>
#include <stdlib.h>

void copy(FILE *from, FILE *to);

int main() {
    char *from = "hello.txt";
    FILE *f = fopen(from, "r");
    if (!f) {
        perror(from);
        exit(1);
    }

    char *to = "output.txt";
    FILE *output_file = fopen(to, "w");
    if (!output_file) {
        perror(to);
        exit(1);
    }

    copy(f, output_file);

    fclose(f);
    fclose(output_file);

}

void copy(FILE *from, FILE *to) {
    int c;
    int n;

    for (;;) {
        c = fgetc(from);

        if (c == EOF) {
            break;
        }

        n = fputc(c, to);

        if (n == EOF) {
            exit(1);
        }
    }
}
