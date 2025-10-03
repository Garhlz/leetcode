// d163
func minSensors(n int, m int, k int) int {
	k = 2*k + 1
	t1 := n / k
	if n%k != 0 {
		t1++
	}
	t2 := m / k
	if m%k != 0 {
		t2++
	}
	return t1 * t2
}