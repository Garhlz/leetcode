func countBinaryPalindromes(n int64) int {
	// Bug 1修正: 特判 n = 0 的情况
	if n == 0 {
		return 1
	}

	// 风格建议: 使用 bits.Len() 更高效简洁
	bitCount := bits.Len(uint(n))

	// Bug 1修正: ans 从 1 开始，自动包含回文数 0
	ans := 1

	// --- 第一部分：统计长度小于 bitCount 的回文数 ---
	// 这部分你的逻辑是正确的
	for i := 1; i < bitCount; i++ {
		ans += (1 << ((i - 1) / 2))
	}

	// --- 第二部分：统计长度等于 bitCount 的回文数 ---

	// Bug 2和3修正: 循环边界是 >=，判断条件是 n 的该位是否为 1
	for i := bitCount - 2; i >= bitCount/2; i-- {
		// (n >> i) & 1 是检查 n 的第 i 位的标准写法
		if (n>>i)&1 == 1 {
			// 这一位可以填 0，那么回文数左半的剩余位置可以随便填
			ans += (1 << (i - bitCount/2))
		}
	}

	// Bug 4修正: 补充最后一步，检查左半部分与 n 相同的那个回文数
	leftHalfN := n >> (bitCount / 2)
	pal := leftHalfN

	// 构造右半部分
	tempLeft := leftHalfN >> (bitCount % 2)
	for v := tempLeft; v > 0; v >>= 1 {
		pal = (pal << 1) | (v & 1)
	}

	// 如果这个候选者也合法，答案加1
	if pal <= n {
		ans++
	}

	return ans
}