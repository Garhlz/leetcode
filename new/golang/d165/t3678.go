package main

import "math"

func smallestAbsent(nums []int) int {
	mp := map[int]struct{}{}
	sum := float64(0)
	for _, x := range nums {
		sum += float64(x)
		mp[x] = struct{}{}
	}
	sum /= float64(len(nums))
	tmp := int(math.Floor(sum))
	ans := 0
	for i := max(tmp+1, 1); ; i++ {
		if _, ok := mp[i]; !ok {
			ans = i
			break
		}
	}
	return ans
}
