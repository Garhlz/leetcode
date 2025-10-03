func bowlSubarrays(nums []int) int64 {
	var ans int64 = 0
	st := []int{}

	for _, x := range nums {
		for len(st) > 0 && st[len(st)-1] < x {
			// 新的栈顶和x构成了len>=3的子数组的边界
			st = st[:len(st)-1]
			if len(st) > 0 {
				ans++
			}
		}
		st = append(st, x)
	}
	return ans
}