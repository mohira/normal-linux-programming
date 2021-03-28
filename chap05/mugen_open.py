import os
from pathlib import Path


def main():
    Path('foo.txt').touch()

    # OSError: [Errno 24] Too many open files: 'foo.txt'
    while True:
        os.open('foo.txt', os.O_RDONLY)


if __name__ == '__main__':
    main()
