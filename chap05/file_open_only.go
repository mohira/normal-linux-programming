package main

import "os"

func main() {
	file, _ := os.Open("sample.txt")
	print(file)
}
