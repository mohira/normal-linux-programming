import os


def main():
    assert open('sample.txt').read() == 'hello world'

    fd = os.open('sample.txt', flags=os.O_RDONLY)

    print(fd)  # 3

    # 5バイト分読み込むことを繰り返す
    print(os.read(fd, 5))  # b'hello'
    print(os.read(fd, 5))  # b' worl'
    print(os.read(fd, 5))  # b'd'
    print(os.read(fd, 5))  # b'' ← 空文字バイト

    os.close(3)

    # OSError: [Errno 9] Bad file descriptor
    os.read(fd, 5)


if __name__ == '__main__':
    main()
