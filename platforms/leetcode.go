package main

import (
	"fmt"
)

func minBitFlips(start int, goal int) int {
	count := 0
	for start > 0 && goal > 0 {
		if start&1 != goal&1 {
			count += 1
		}
		start, goal = start>>1, goal>>1
	}
	for start > 0 {
		if start&1 != 0 {
			count += 1
		}
		start = start >> 1
	}
	for goal > 0 {
		if goal&1 != 0 {
			count += 1
		}
		goal = goal >> 1
	}
	return count
}

func main() {
	start := 3
	goal := 4
	fmt.Println(minBitFlips(start, goal))
}
