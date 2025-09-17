/*
 * @lc app=leetcode.cn id=307 lang=golang
 *
 * [307] 区域和检索 - 数组可修改
 */

// @lc code=start
type NumArray struct {
	nums []int
	tree []int
}

func Constructor(nums []int) NumArray {
	tree := make([]int, len(nums)+1)
	for i, x := range nums {
		i++
		for j := i; j < len(tree); j += j & -j {
			tree[j] += x
		}
	}
	return NumArray{nums, tree}
}

func (a *NumArray) Update(index int, val int) {
	delta := val - a.nums[index]
	a.nums[index] = val
	for i := index + 1; i < len(a.tree); i += i & -i {
		a.tree[i] += delta
	}
}

func (a *NumArray) prefixSum(i int) (s int) {
	for ; i > 0; i -= (i & -i) {
		s += a.tree[i]
	}
	return
}

func (a *NumArray) SumRange(left int, right int) int {
	return a.prefixSum(right+1) - a.prefixSum(left)
}

/**
 * Your NumArray object will be instantiated and called as such:
 * obj := Constructor(nums);
 * obj.Update(index,val);
 * param_2 := obj.SumRange(left,right);
 */
// @lc code=end

