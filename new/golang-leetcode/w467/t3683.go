package main

import "math"

func earliestTime(tasks [][]int) int {
	mn := math.MaxInt
	for _, t := range tasks {
		mn = min(mn, t[0]+t[1])
	}
	return mn
}
