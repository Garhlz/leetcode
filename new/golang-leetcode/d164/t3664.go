package main

func f(sum, mx, extra int) int {
	sum += extra
	mx = max(mx, extra)
	return min(sum-mx, sum/2)
}

func score(cards []string, x byte) int {
	a, b, c := 0, 0, 0
	mp1, mp2 := map[byte]int{}, map[byte]int{}
	mx1, mx2 := 0, 0
	for _, card := range cards {
		if card[0] == x && card[1] == x {
			c++
		} else if card[0] == x {
			a++
			mp1[card[1]]++
			mx1 = max(mx1, mp1[card[1]])
		} else if card[1] == x {
			b++
			mp2[card[0]]++
			mx2 = max(mx2, mp2[card[0]])
		}
	}
	ans := 0
	for k := range c + 1 { // k给第一组， c - k给第二组
		ans1 := f(a, mx1, k)
		ans2 := f(b, mx2, c-k)
		ans = max(ans, ans1+ans2)
	}
	return ans
}

// func main() {
// 	// cards := []string{"ce", "ca", "ca", "ee", "cd"}
// 	// result := score(cards, 'c')
// 	cards := []string{"ab", "aa", "ab", "bc", "cc", "bc", "bb", "ac", "bc", "bc", "aa", "aa", "ba", "bc", "cb", "ba", "ac", "bb", "cb", "ac", "cb", "cb", "ba", "bc", "ca", "ba", "bb", "cc", "cc", "ca", "ab", "bb", "bc", "ba", "ac", "bc", "ac", "ac", "bc", "bb", "bc", "ac", "bc", "aa", "ba", "cc", "ac", "bb", "ba", "bb"}
// 	result := score(cards, 'b')
// 	fmt.Printf("result: %v\n", result)
// }
