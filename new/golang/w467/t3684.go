package main

import "slices"

// 1. 去重，slices.Compact
// 2. 没有规定k和nums长度的关系
func maxKDistinct(nums []int, k int) []int {
	slices.SortFunc(nums, func(a, b int) int {
		return b - a
	})
	nums = slices.Compact(nums)
	if k < len(nums) {
		return nums[:k]
	} else {
		return nums
	}
}
