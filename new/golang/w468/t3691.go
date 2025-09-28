package main

import (
	"container/heap"
	"fmt"
)

type pair struct {
	val, idx int
}

type SparseTable struct {
	logTable []int
	stMax    [][]pair
	stMin    [][]pair
}

func NewSparseTable(nums []int) *SparseTable {
	n := len(nums)
	if n == 0 {
		return nil
	}

	logTable := make([]int, n+1)
	for i := 2; i <= n; i++ {
		logTable[i] = logTable[i/2] + 1
	}

	maxLog := logTable[n]
	stMax := make([][]pair, n)
	stMin := make([][]pair, n)
	for i := 0; i < n; i++ {
		stMax[i] = make([]pair, maxLog+1)
		stMin[i] = make([]pair, maxLog+1)
	}

	for i := 0; i < n; i++ {
		stMax[i][0] = pair{val: nums[i], idx: i}
		stMin[i][0] = pair{val: nums[i], idx: i}
	}

	for j := 1; j <= maxLog; j++ {
		for i := 0; i+(1<<j) <= n; i++ {
			p1Max := stMax[i][j-1]
			p2Max := stMax[i+(1<<(j-1))][j-1]

			// 如果值相等，我们优先选择下标较小的那个
			if p1Max.val >= p2Max.val {
				stMax[i][j] = p1Max
			} else {
				stMax[i][j] = p2Max
			}

			p1Min := stMin[i][j-1]
			p2Min := stMin[i+(1<<(j-1))][j-1]
			// 如果值相等，我们优先选择下标较小的那个
			if p1Min.val <= p2Min.val {
				stMin[i][j] = p1Min
			} else {
				stMin[i][j] = p2Min
			}
		}
	}

	return &SparseTable{
		logTable: logTable,
		stMax:    stMax,
		stMin:    stMin,
	}
}

func (st *SparseTable) QueryMax(l, r int) pair {
	length := r - l + 1
	if length <= 0 {
		return pair{-1, -1}
	}

	k := st.logTable[length]

	p1 := st.stMax[l][k]
	p2 := st.stMax[r-(1<<k)+1][k]

	if p1.val >= p2.val {
		return p1
	} else {
		return p2
	}
}

func (st *SparseTable) QueryMin(l, r int) pair {
	length := r - l + 1
	if length <= 0 {
		return pair{-1, -1}
	}
	k := st.logTable[length]

	p1 := st.stMin[l][k]
	p2 := st.stMin[r-(1<<k)+1][k]

	if p1.val <= p2.val {
		return p1
	}
	return p2
}

func (st *SparseTable) query(l, r int) int {
	if l >= r {
		return 0
	}
	return st.QueryMax(l, r).val - st.QueryMin(l, r).val
}

type tuple struct{ val, l, r int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].val > h[j].val } // 最大堆
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() any {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}

func maxTotalValue(nums []int, k int) int64 {
	n := len(nums)
	st := NewSparseTable(nums)
	ans := int64(0)
	h := &hp{{st.query(0, n-1), 0, n - 1}}
	for ; k > 0 && len(*h) > 0 && (*h)[0].val > 0; k-- {
		top := heap.Pop(h).(tuple)
		ans += int64(top.val)

		l, r := top.l, top.r

		if r > l {
			heap.Push(h, tuple{st.query(l, r-1), l, r - 1})
		}

		if r == n-1 && l < n-1 {
			heap.Push(h, tuple{st.query(l+1, r), l + 1, r})
		}
	}
	return ans
}

func main() {
	fmt.Println(maxTotalValue([]int{1, 3, 2}, 2))    // Output: 4
	fmt.Println(maxTotalValue([]int{4, 2, 5, 1}, 3)) // Output: 12
}
