func perfectPairs(nums []int) int64 {
	for i, x := range nums {
		if x < 0 {
			nums[i] *= -1
		}
	}
	var ans int64
	slices.Sort(nums)
	slow := 0
	for j, big := range nums {
		for nums[slow]*2 < big {
			slow++
		}
		ans += int64(j - slow)
	}
	return ans
}

// min(abs(a-b), abs(a+b)) <= min(abs(a), abs(b))