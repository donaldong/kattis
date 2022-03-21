package main

import (
	"fmt"
)

func harshad(n int) bool {
	sd := 0
	s := fmt.Sprintf("%v", n)
	for _, c := range s {
		sd += int(c) - int("0"[0])
	}
	return n % sd == 0
}

func main() {
	var n int
	fmt.Scanln(&n)
	for !harshad(n) {
		n += 1
	}
	fmt.Println(n)
}
