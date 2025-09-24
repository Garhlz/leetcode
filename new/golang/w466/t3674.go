// w466
package main

func minOperations(nums []int) int {
	mp := map[int]int{}
	for _, x := range nums {
		mp[x]++
	}
	if len(mp) > 1 {
		return 1
	} else {
		return 0
	}
}
