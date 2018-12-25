package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var (
	reader = bufio.NewReader(os.Stdin)
)

func rl() []int64 {
	line, _ := reader.ReadString('\n')
	F := strings.Fields(line)
	res := make([]int64, len(F))
	for i, f := range F {
		res[i], _ = strconv.ParseInt(f, 10, 64)
	}
	return res
}

func main() {
	T := rl()
	q := T[1]
	D := rl()
	for t := int64(0); t < q; t++ {
		T = rl()
		if T[0] == 1 {
			D[T[1] - 1] = T[2]
		} else {
			diff := D[T[1] - 1] - D[T[2] - 1]
			if diff < 0 {
				diff *= -1
			}
			fmt.Println(diff)
		}
	}
}
