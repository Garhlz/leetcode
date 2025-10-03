// w465

func recoverOrder(order []int, friends []int) []int {
	isFriend = make(map[int]struct{})
	for _, friendID := range friends {
		isFriend[friendID] = struct{}{}
	}

	ans := make([]int, 0, len(friends))

	for _, id := range order {
		if _, ok := isFriend[id]; ok {
			ans = append(ans, id)
		}
	}
	return ans
}