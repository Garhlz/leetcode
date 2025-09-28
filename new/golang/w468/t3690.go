package main

import "slices"

func minSplitMerge(nums1 []int, nums2 []int) int {
	n := len(nums1)
	ans := 0
	tmp := [6]int{}
	copy(tmp[:], nums1)
	vis := map[[6]int]bool{tmp: true}
	q := [][]int{nums1}

	for ; ; ans++ {
		tmp := q
		q = nil
		for _, arr := range tmp {
			if slices.Equal(arr, nums2) {
				return ans
			}
			for l := 0; l < n; l++ {
				for r := l + 1; r <= n; r++ {
					sub := arr[l:r]
					b := append(slices.Clone(arr[:l]), arr[r:]...)
					for i := 0; i <= len(b); i++ {
						c := slices.Insert(slices.Clone(b), i, sub...)
						t := [6]int{}
						copy(t[:], c)
						if !vis[t] {
							vis[t] = true
							q = append(q, c)
						}
					}
				}
			}

		}
	}
}
