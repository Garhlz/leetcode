// 升序排序之后， 求最长的最小最大值的倍数相距小于等于k倍的长度
// 双指针即可
func minRemoval(nums []int, k int) int {
	slices.Sort(nums)
	n := len(nums)
	fi := 0
	mx := 1
	for si, slow := range nums {
		for fi < n && nums[fi] <= slow*k {
			fi++
		}
		// 此时的fi表示没有取到的第一个数字
		mx = max(mx, fi-1-si+1)
	}
	return n - mx
}