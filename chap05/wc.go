package main

import (
	"fmt"
	"io/ioutil"
	"log"
	"os"
	"strings"
)

func main() {
	args := os.Args

	if len(args) < 2 {
		os.Exit(1)
	}

	var totalLine int
	for _, arg := range args[1:] {
		file, err := os.Open(arg)
		if err != nil {
			log.Fatal(err)
		}

		bytes, err := ioutil.ReadAll(file)
		if err != nil {
			log.Fatal(err)
		}
		_ = file.Close()

		c := strings.Count(string(bytes), "\n")
		fmt.Printf("\t%d\t%s\n", c, file.Name())

		totalLine += c
	}

	fmt.Printf("\t%d\ttotal\n", totalLine)
}
