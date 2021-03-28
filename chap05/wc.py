import os
import sys


def main():
    args = sys.argv

    if len(args) < 2:
        exit(1)

    total_lines = 0
    for arg in args[1:]:
        try:
            fd = os.open(arg, os.O_RDONLY)
        except FileNotFoundError as e:
            print(e)
            continue

        line_count = 0

        while True:
            byte = os.read(fd, 1)

            if byte == b'\n':
                line_count += 1

            if byte == b'':
                os.write(sys.stdout.fileno(), f'{line_count}\t{arg}\n'.encode())
                break

        total_lines += line_count

    print(f'{total_lines}\ttotal')


def main2():
    args = sys.argv

    if len(args) < 2:
        exit(1)

    for arg in args[1:]:
        if os.path.exists(arg):
            with open(arg, mode='r') as f:
                line_count = f.read().count('\n')
                print(f'{line_count} {arg}')
        else:
            exit(1)


if __name__ == '__main__':
    main()
