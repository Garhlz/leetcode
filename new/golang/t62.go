func uniquePaths(m, n int) int {
	memo := make([][]int, m)
	for i := range memo {
		memo[i] = make([]int, n)
	}
	memo[0][0] = 1
	var dfs func(int, int) int
	dfs = func(i, j int) int {
		if i < 0 || j < 0 || i >= m || j >= n {
			return 0
		}
		if memo[i][j] == 0 {
			memo[i][j] = dfs(i-1, j) + dfs(i, j-1)
		}
		return memo[i][j]
	}
	return dfs(m-1, n-1)
}