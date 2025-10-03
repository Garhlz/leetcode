func partitionArray(nums []int, k int) bool {
	length := len(nums)
	if length%k != 0 {
		return false
	}
	numMap := map[int]int{}
	mx := 0
	for _, x := range nums {
		numMap[x]++
		mx = max(mx, numMap[x])
	}
	return mx <= length/k
}