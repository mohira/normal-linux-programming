package main

import (
	"io"
	"log"
	"os"
)

func main() {
	if len(os.Args) == 1 {
		doCat2(os.Stdin)
	} else {
		for _, arg := range os.Args[1:] {
			file, err := os.Open(arg)

			if err != nil {
				log.Fatal(err)
			}

			doCat2(file)
			file.Close()
		}
	}
}

func doCat2(r io.Reader) {
	if _, err := io.Copy(os.Stdout, r); err != nil {
		log.Fatal(err)
	}
}
