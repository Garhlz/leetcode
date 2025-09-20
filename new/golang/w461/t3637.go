package main

// 周赛461
func isTrionic(nums []int) bool {
	n := len(nums)
	dif := make([]int, n)
	for i := 1; i < n; i++ {
		dif[i] = nums[i] - nums[i-1]
	}
	flag := 0
	for i := 1; i < n; i++ {
		if flag == 0 {
			if dif[i] > 0 {
				flag = 1
			} else {
				return false
			}
		} else if flag == 1 {
			if dif[i] > 0 {
				continue
			} else if dif[i] < 0 {
				flag = 2
			} else {
				return false
			}
		} else if flag == 2 {
			if dif[i] < 0 {
				continue
			} else if dif[i] > 0 {
				flag = 3
			} else {
				return false
			}
		} else if flag == 3 {
			if dif[i] > 0 {
				continue
			} else {
				return false
			}
		}
	}
	if flag == 3 {
		return true
	} else {
		return false
	}
}

// func main() {
// 	nums := []int{4, 1, 5, 2, 3}
// 	fmt.Println(isTrionic(nums))
// }
