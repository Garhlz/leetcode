package main

import (
	"math"
	"slices"
)

const mx = 100_001

var divisors [mx][]int // 二维数组，存储每个数字的因数

func init() {
	for i := 1; i < mx; i++ {
		for j := i; j < mx; j += i {
			divisors[j] = append(divisors[j], i)
			// 筛法，通过倍数的方式预处理所有因数
		}
	}
}

func minDifference(n int, k int) []int {
	var ans []int
	minDiff := math.MaxInt
	path := make([]int, k)

	// 使用闭包可以访问外部变量
	var dfs func(int, int)
	dfs = func(i, cur int) {
		if i == k-1 {
			if cur-path[0] < minDiff {
				minDiff = cur - path[0]
				path[i] = cur
				ans = slices.Clone(path)
			}
			return
		}

		for _, now := range divisors[cur] {
			if now*now > cur {
				break
			}
			if i > 0 && now-path[0] >= minDiff {
				break
			}
			if i == 0 || now >= path[i-1] {
				path[i] = now
				dfs(i+1, cur/now)
			}
		}
	}

	dfs(0, n)
	return ans

}

// func main() {
// 	// 示例 1
// 	n1, k1 := 100, 2
// 	fmt.Printf("输入: n=%d, k=%d\n", n1, k1)
// 	fmt.Printf("输出: %v (预期: [10, 10])\n\n", minDifference(n1, k1))

// 	// 示例 2
// 	n2, k2 := 44, 3
// 	fmt.Printf("输入: n=%d, k=%d\n", n2, k2)
// 	fmt.Printf("输出: %v (预期: [2, 2, 11])\n\n", minDifference(n2, k2))
// }
