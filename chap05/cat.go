package main

import (
	"fmt"
	"io"
	"log"
	"os"
)

const BufferSize = 2048

func main() {
	argc := len(os.Args)

	if argc < 2 {
		_, _ = fmt.Fprintf(os.Stderr, "%s: file name not given\n", os.Args[0])
		os.Exit(1)
	}

	for _, path := range os.Args[1:] {
		doCat(path)
	}

}


func doCat(path string) {
	buf := make([]byte, BufferSize)

	file, err := os.Open(path)
	defer file.Close()

	if err != nil {
		log.Fatal(err)
	}

	for {
		// Goなら読み込んだバイト数じゃなくてerrで判定するよな
		_, err := file.Read(buf)

		if err == io.EOF {
			break
		}

		if _, err := io.WriteString(os.Stdout, string(buf)); err != nil {
			log.Fatal(err)
		}

		if err != nil {
			log.Fatal(err)
		}

	}
}
