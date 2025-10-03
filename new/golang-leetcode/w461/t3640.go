func maxSumTrionic(nums []int) int64 {
	n := len(nums)
	ans := math.MinInt

	for i := 0; i < n; {
		start := i
		i++
		for ; i < n && nums[i-1] < nums[i]; i++ {
		}
		if i == start+1 { // 此时的i是没有用上的
			continue
		}
		peak := i - 1 // 这个数字已经被第一段选了

		res := nums[peak-1] + nums[peak] // 必选的数字
		for ; i < n && nums[i-1] > nums[i]; i++ {
			res += nums[i]
		}
		// 最后一个i是没有选择的数字, 已经递增
		if i == peak+1 || i == n || nums[i-1] == nums[i] {
			continue
		}
		bottom := i - 1

		res += nums[i]
		mx, now := 0, 0

		for i++; i < n && nums[i-1] < nums[i]; i++ {
			now += nums[i]
			mx = max(mx, now)
		}
		res += mx

		mx, now = 0, 0
		for j := peak - 2; j >= start; j-- {
			now += nums[j]
			mx = max(mx, now)
		}
		res += mx

		ans = max(ans, res)
		i = bottom
	}
	return int64(ans)
}