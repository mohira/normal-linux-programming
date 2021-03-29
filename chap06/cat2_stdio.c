#include <stdio.h>
#include <stdlib.h>

// stdio版catコマンド
// 標準力には対応していないよ
int main(int argc, char *argv[]){
    for (int i = 1; i < argc; ++i) {
        FILE *f;
        f = fopen(argv[i], "r");
        if (!f) {
            perror(argv[i]);
            exit(1);
        }
        int c;
        while ((c = fgetc(f)) != EOF) {
            // 標準出力がパイプだったりすると、そのパイプの先にいるプロセスが終了したあとに書き込みでエラーがおこるらしい
            if (putchar(c) < 0) {
                exit(1);
            }
        }
        fclose(f);
    }

    exit(0);
}