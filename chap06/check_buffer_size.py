import io


# https://docs.python.org/ja/3/library/io.html#io.DEFAULT_BUFFER_SIZE
# head -c 33554432 /dev/urandom > dummy33554432.dat

def main():
    f = open('dummy33554432.dat', 'rb')

    f.read()
    f.close()

    print(io.DEFAULT_BUFFER_SIZE)


if __name__ == '__main__':
    main()
