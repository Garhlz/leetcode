// d164
func getLeastFrequentDigit(n int) int {
	cnt := map[int]int{}
	var ans int = n % 10
	for n > 0 {
		cnt[n%10]++
		n /= 10
	}

	for key, val := range cnt {
		if val < cnt[ans] || (val == cnt[ans] && key < ans) {
			ans = key
		}
	}
	return ans
}