package main

import (
	"math/bits"
	"slices"
)

type base []int

func newBase(n int) base {
	return make(base, n)
}

func (b base) insert(x int) {
	for i := len(b) - 1; i >= 0; i-- {
		if (x>>i)&1 == 0 {
			continue
		}
		if b[i] == 0 {
			b[i] = x
			return
		}
		x ^= b[i]
	}
}

func (b base) maxXor() int {
	res := 0
	for i := len(b) - 1; i >= 0; i-- {
		res = max(res, res^b[i])
	}
	return res
}

func maxXorSubsequences(nums []int) int {
	u := slices.Max(nums)
	m := bits.Len(uint(u))
	b := newBase(m)
	for _, x := range nums {
		b.insert(x)
	}
	return b.maxXor()
}
