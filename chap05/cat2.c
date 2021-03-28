#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>


void do_cat2(FILE *pFile);

int main(int argc, char *argv[]) {
    if (argc == 1) {
        do_cat2(stdin);
    } else {
        for (int i = 1; i < argc; ++i) {
            char *filename = argv[i];
            FILE *f;

            f = fopen(filename, "r");

            if (!f) {
                perror(filename);
                exit(1);
            }

            do_cat2(f);
            fclose(f);
        }
    }
}

void do_cat2(FILE *f) {
    int c;

    while ((c = fgetc(f)) != EOF) {
        // The patcher() function is identical to putc() with an output stream of stdout.
        if (putchar(c) < 0) {
            exit(1);
        }
    }

}
