package main

func minArrivalsToDiscard(arrivals []int, w int, m int) int {
	mp := map[int]int{}
	ans := 0
	for i := 0; i < len(arrivals); i++ {
		// 先将滑动窗口外的出队
		if i-w >= 0 && arrivals[i-w] != 0 {
			mp[arrivals[i-w]]--
		}

		mp[arrivals[i]]++
		if mp[arrivals[i]] > m {
			mp[arrivals[i]]--
			arrivals[i] = 0
			ans++
		}
	}
	return ans
}

// func main() {
// 	fmt.Println(minArrivalsToDiscard([]int{10, 4, 3, 6, 4, 5, 6, 1, 4}, 7, 1))
// 	// 不可以无脑丢弃前面的数字
// }
