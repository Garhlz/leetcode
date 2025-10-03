package main

import (
	"math/bits"
	"slices"
)

// 题意要求计算nums数组中所有两个想与=0的数字的最大乘积，考虑用集合的思想计算数组中的数字的位的集合的最大的子集数字
// 用了一种神奇的数位dp的方式计算这个，就是从小到大把为1的位置0之后继承这一位的大小
func maxProduct(nums []int) int64 {
	mx := 0
	if len(nums) > 0 {
		mx = slices.Max(nums)
	}
	if mx == 0 {
		return 0
	}

	w := bits.Len(uint(mx)) // 最大值的二进制长度
	u := 1 << w

	f := make([]int, u) // f[mask] 将存储所有 “x 的二进制是 mask 的子集” 的 x 中，最大的那个值。
	for _, x := range nums {
		f[x] = x
	}

	for i := 0; i < w; i++ {
		for s := 0; s < u; s++ {
			if s&(1<<i) != 0 {
				f[s] = max(f[s], f[s^(1<<i)])
				// s是s^(1<<i)的超集（把对应位置0）
			}
		}
	}
	var ans int64 = 0
	for _, x := range nums {
		complement := (u - 1) ^ x
		partner := f[complement]
		ans = max(ans, (int64)(x*partner))
	}
	return ans
}

// func main() {
// 	// 示例 1
// 	nums1 := []int{1, 2, 3, 4, 5, 6, 7}
// 	fmt.Printf("输入: %v\n", nums1)
// 	fmt.Printf("输出: %d (预期: 12)\n\n", maxProduct(nums1))

// 	// 示例 2
// 	nums2 := []int{5, 6, 4}
// 	fmt.Printf("输入: %v\n", nums2)
// 	fmt.Printf("输出: %d (预期: 0)\n\n", maxProduct(nums2))

// 	// 示例 3
// 	nums3 := []int{64, 8, 32}
// 	fmt.Printf("输入: %v\n", nums3)
// 	fmt.Printf("输出: %d (预期: 2048)\n\n", maxProduct(nums3))
// }
