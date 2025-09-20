package main

import "sort"

func minTime(s string, order []int, k int) int {
	n := len(order)
	if k > (n+1)*n/2 {
		return -1
	}
	if k == 0 {
		return 0
	}

	ans := sort.Search(n, func(now int) bool {
		star := make([]bool, n)
		for _, j := range order[:now+1] {
			star[j] = true // 当前已经被标记了
		}

		cnt := 0
		last := -1 // 表示上一个最近的已经被标记的位置
		for i := 0; i < n; i++ {
			if star[i] {
				last = i
			}
			cnt += last + 1
		}
		return cnt >= k
	})
	// 直接调用这个sort.Search函数， 表示二分查找[0,n-1]中第一个满足该函数的数字
	return ans
}
