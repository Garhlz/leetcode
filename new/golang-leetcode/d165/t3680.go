package main

func generateSchedule(n int) [][]int {
	if n < 5 {
		return nil
	}
	ans := make([][]int, 0, n*(n-1))

	for d := 2; d < n-1; d++ {
		for i := range n {
			ans = append(ans, []int{i, (i + d) % n})
		}
	}

	for i := range n {
		ans = append(ans, []int{i, (i + 1) % n}, []int{(i - 1 + n) % n, (i - 2 + n) % n})
	}
	return ans
}
