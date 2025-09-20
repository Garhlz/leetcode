package main

import (
	"cmp"
	"math"
	"slices"
)

func subarrayMajority(nums []int, queries [][]int) []int {
	n, m := len(nums), len(queries)

	cnt := map[int]int{}

	maxCnt, minVal := 0, 0
	add := func(x int) {
		cnt[x]++
		c := cnt[x]
		if c > maxCnt {
			maxCnt, minVal = c, x
		} else if c == maxCnt {
			minVal = min(minVal, x)
		}
	}

	ans := make([]int, m) // 需要记录query的顺序id
	blockSize := int(math.Ceil(float64(n) / math.Sqrt(float64(m*2))))
	type query struct{ bid, l, r, threshold, qid int }
	qs := make([]query, 0, m)

	for i, q := range queries {
		l, r, threshold := q[0], q[1], q[2]

		if r-l+1 > blockSize {
			qs = append(qs, query{l / blockSize, l, r, threshold, i})
			continue
		}

		for _, x := range nums[l : r+1] {
			add(x)
		}
		if maxCnt >= threshold {
			ans[i] = minVal
		} else {
			ans[i] = -1
		}
		clear(cnt)
		maxCnt = 0
	}
	slices.SortFunc(qs, func(a, b query) int {
		return cmp.Or(a.bid-b.bid, a.r-b.r)
	})

	var curR int
	for i, q := range qs {
		l0 := (q.bid + 1) * blockSize
		if i == 0 || q.bid > qs[i-1].bid {
			curR = l0
			clear(cnt)
			maxCnt = 0
		}
		for ; curR <= q.r; curR++ {
			add(nums[curR])
		}

		tmpMaxCnt, tmpMinVal := maxCnt, minVal

		for _, x := range nums[q.l:l0] {
			add(x)
		}
		if maxCnt >= q.threshold {
			ans[q.qid] = minVal
		} else {
			ans[q.qid] = -1
		}
		// 回滚，每次从右侧端点重新计算
		maxCnt, minVal = tmpMaxCnt, tmpMinVal
		for _, x := range nums[q.l:l0] {
			cnt[x]--
		}
	}
	return ans
}
