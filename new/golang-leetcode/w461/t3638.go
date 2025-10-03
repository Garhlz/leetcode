package main

// 看差分数组，每间隔一个位置就可以取一次，求最大的取的数量
func maxBalancedShipments(weight []int) int {
	n := len(weight)
	dif := make([]int, n)
	for i := 1; i < n; i++ {
		dif[i] = weight[i] - weight[i-1]
	}
	ans := 0
	for i := 1; i < n; i++ {
		if dif[i] < 0 {
			ans++
			i++
		}
	}
	return ans
}
