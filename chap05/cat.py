import os
import sys


def main():
    argv = sys.argv
    argc = len(argv)

    if argc < 2:
        print(f'{argv[0]}: file name not given', file=sys.stderr)
        exit(1)

    for file_path in argv[1:]:
        do_cat(file_path)


def do_cat(file_path: str) -> None:
    buffer_size = 6

    fd = os.open(file_path, os.O_RDONLY)

    while True:
        byte = os.read(fd, buffer_size)

        if len(byte) == 0:
            break

        os.write(sys.stdout.fileno(), byte)


if __name__ == '__main__':
    main()
