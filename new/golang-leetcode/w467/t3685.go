package main

import (
	"slices"
)

func subsequenceSumAfterCapping(nums []int, k int) []bool {
	n := len(nums)
	slices.Sort(nums)
	dp := make([][]bool, len(nums))
	for i := range dp {
		dp[i] = make([]bool, k+1)
	}
	dp[0][0] = true
	if nums[0] <= k {
		dp[0][nums[0]] = true // 取nums的前i个数字, 可以达到的所有k以下的数
	}
	for i := 1; i < len(nums); i++ {
		for j := 0; j <= k; j++ {
			dp[i][j] = dp[i-1][j]
			if j >= nums[i] {
				dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]] // 继承
			}
		}
		if dp[i][k] == true { // 已经找到了一种达到k的组合， 直接结束即可
			for j := i + 1; j < len(nums); j++ {
				dp[j][k] = true
			}
			break
		}
	}

	ans := make([]bool, n)
	pos := 0 // nums数组中可以利用的位置
	for i := 0; i < n; i++ {
		for pos < n && nums[pos] <= i+1 {
			pos++
		} // 最后一个不可以取到
		if pos == 0 {
			if k%(i+1) == 0 && k/(i+1) <= n {
				ans[i] = true
			} else {
				ans[i] = false
			}
			continue
		}
		if dp[pos-1][k] {
			ans[i] = true
			continue
		}
		cnt := n - 1 - pos + 1
		// 循环中同时控制两个变量
		// 注意这里是可以减掉cnt个i+1,所以是小于等于
		for now, j := k, 0; now >= 0 && j <= cnt; now, j = now-i-1, j+1 {
			if dp[pos-1][now] {
				ans[i] = true
				break
			}
		}
	}
	return ans
}

// func main() {
// 	nums := []int{2, 6, 3, 6, 5, 6, 2, 8}
// 	k := 29
// 	fmt.Println(subsequenceSumAfterCapping(nums, k))
// }
