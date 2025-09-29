package main

// import (
// 	"container/heap"
// 	"math/bits"
// )

// // --- ST表部分 ---
// // pair 存储一个区间的min和max
// type pair struct{ min, max int }

// // op 定义了如何合并两个pair
// func op(a, b pair) pair {
// 	if a.min > b.min {
// 		a.min = b.min
// 	}
// 	if a.max < b.max {
// 		a.max = b.max
// 	}
// 	return a
// }

// // ST 定义，16是根据 n<=5e4 估算的 log2(n) 上限
// type ST [][16]pair

// func newST(a []int) ST {
// 	n := len(a)
// 	w := bits.Len(uint(n))
// 	st := make(ST, n)
// 	for i, x := range a {
// 		st[i][0] = pair{x, x}
// 	}
// 	for j := 1; j < w; j++ {
// 		for i := 0; i+(1<<j) <= n; i++ {
// 			st[i][j] = op(st[i][j-1], st[i+(1<<(j-1))][j-1])
// 		}
// 	}
// 	return st
// }

// // query 查询左闭右开区间 [l, r) 的 max-min
// func (st ST) query(l, r int) int {
// 	if l >= r {
// 		return 0
// 	} // 区间无效
// 	k := bits.Len(uint(r-l)) - 1
// 	p := op(st[l][k], st[r-(1<<k)][k])
// 	return p.max - p.min
// }

// // --- 最大堆部分 ---
// // tuple 存储一个子数组的信息：值，左端点，右端点（开）
// type tuple struct{ val, l, r int }
// type hp []tuple

// func (h hp) Len() int           { return len(h) }
// func (h hp) Less(i, j int) bool { return h[i].val > h[j].val } // 最大堆
// func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
// func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
// func (h *hp) Pop() any {
// 	old := *h
// 	n := len(old)
// 	x := old[n-1]
// 	*h = old[0 : n-1]
// 	return x
// }

// // --- 主函数 ---
// func maxTotalValue(nums []int, k int) (ans int64) {
// 	n := len(nums)
// 	st := newST(nums)

// 	// 初始化堆，只放入第一个列表的最大元素
// 	h := &hp{{st.query(0, n), 0, n}}

// 	// 循环k次，或者堆为空/堆顶为0
// 	for ; k > 0 && len(*h) > 0 && (*h)[0].val > 0; k-- {
// 		top := heap.Pop(h).(tuple)
// 		ans += int64(top.val)

// 		l, r := top.l, top.r

// 		// 1. 将当前列表的“次大值”入堆
// 		if r-1 > l {
// 			heap.Push(h, tuple{st.query(l, r-1), l, r - 1})
// 		}

// 		// 2. 如果弹出的是某个列表的最大值 (r==n)，则“解锁”下一个列表的最大值
// 		if r == n && l+1 < n {
// 			heap.Push(h, tuple{st.query(l+1, n), l + 1, n})
// 		}
// 	}
// 	return
// }
