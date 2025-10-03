func maxValue(nums []int) []int {
	n := len(nums)
	ans := make([]int, n)
	preMax := make([]int, n)
	sufMin := make([]int, n)
	preMax[0] = nums[0]
	for i := 1; i < n; i++ {
		preMax[i] = max(preMax[i-1], nums[i])
	}
	sufMin[n-1] = nums[n-1]
	for i := n - 2; i >= 0; i-- {
		sufMin[i] = min(sufMin[i+1], nums[i])
	}
	ans[n-1] = preMax[n-1]

	for i := n - 2; i >= 0; i-- {
		if preMax[i] <= sufMin[i+1] {
			ans[i] = preMax[i]
		} else {
			ans[i] = ans[i+1]
		}
	}
	return ans
}