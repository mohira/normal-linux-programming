#include <stdio.h>
#include <stdlib.h>

int count_line(FILE *f);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        printf("\t%d\n", count_line(stdin));

    } else {
        for (int i = 1; i < argc; i++) {
            char *filename = argv[i];
            FILE *f = fopen(filename, "r");

            if (!f) {
                perror(filename);
                exit(1);
            }

            printf("\t%d: %s\n", count_line(f), filename);

            fclose(f);
        }
    }

    exit(0);
}


int count_line(FILE *f) {
    int count = 0;
    int c;

    while ((c = getc(f)) != EOF) {
        // if (c == 10) でも同じ挙動
        if (c == '\n') {
            count++;
        }
    }

    return count;
}
