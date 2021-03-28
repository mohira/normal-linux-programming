import os
import sys
from pathlib import Path
from typing import TextIO


def do_cat2(f: TextIO) -> None:
    while True:
        b = os.read(f.fileno(), 1)
        n = os.write(sys.stdout.fileno(), b)

        if n == 0:
            break


def main():
    argv = sys.argv

    if len(argv) == 1:
        do_cat2(sys.stdin)
    else:
        for arg in argv[1:]:
            if os.path.exists(arg):
                with open(arg) as f:
                    do_cat2(f)
            else:
                print(f'file "{arg}" does not exist', file=sys.stderr)
                exit(1)

            # もっと低レイヤーすぎると、整数を渡すことになるので扱いづらい
            # ファイルがない場合 -1 じゃなくて、FileNotFoundErrorを出すのでイマイチ
            # fd = os.open(arg, os.O_RDONLY)
            # print(fd)

            # pathlibの場合は、.fileno()とか使えないので注意ね
            # file_path = Path(arg)
            #
            # if file_path.exists():
            #     with file_path.open(mode='r'):
            #         do_cat2(file_path)
            # else:
            #     print(f'file "{file_path}" does not exist', file=sys.stderr)


if __name__ == '__main__':
    main()
