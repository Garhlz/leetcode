package main

func countStableSubsequences(nums []int) int {
	const mod = 1e9 + 7
	// 结尾是奇数还是偶数，长度是1还是2
	cnt := [2][2]int{{0, 0}, {0, 0}}
	for _, x := range nums {
		t := x % 2
		cnt[t][1] = (cnt[t][1] + cnt[t][0]) % mod
		cnt[t][0] = (cnt[t][0] + cnt[t^1][0] + cnt[t^1][1] + 1) % mod // 继承奇偶性相反的, 以及相同奇偶，长度=1的子序列（自身）
	}
	return (cnt[0][0] + cnt[0][1] + cnt[1][0] + cnt[1][1]) % mod
}
