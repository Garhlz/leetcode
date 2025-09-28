package main

import "slices"

func maxTotalValue0(nums []int, k int) int64 {
	mx, mn := int64(slices.Max(nums)), int64(slices.Min(nums))
	return int64(k) * (mx - mn)
}
