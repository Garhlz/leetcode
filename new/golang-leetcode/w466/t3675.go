func minOperations(s string) int {
	mn := 'z' + 1
	for _, x := range s {
		if x != 'a' {
			mn = min(mn, x)
		}
	}
	return int('z' + 1 - mn)
}