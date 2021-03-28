#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

// 激遅バージョン
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "%s: file name not given\n", argv[0]);
        exit(1);
    }

    for (int i = 1; i < argc; i++) {
        int fd = open(argv[i], O_RDONLY);

        unsigned char buf[1];

        int count = 0;

        for (;;) {
            int n = read(fd, buf, sizeof buf);

            if (buf[0] == '\n') {
                count++;
            }
            if (n == 0) {
                printf("%d: %s", count, argv[i]);
                break;
            }
        }


    }


}