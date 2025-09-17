func allPathsSourceTarget(graph [][]int) (ans [][]int) {
	stk := []int{0}
	var dfs func(int)
	n := len(graph)
	dfs = func(x int) {
		if x == n-1 {
			ans = append(ans, append([]int(nil), stk...))
			return
		}
		for _, y := range graph[x] {
			stk = append(stk, y)
			dfs(y)
			stk = stk[:len(stk)-1]
		}
	}
	dfs(0)
	return
}