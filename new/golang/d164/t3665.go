func uniquePaths(grid [][]int) int {
	const mod = 1_000_000_007
	m := len(grid)
	n := len(grid[0])
	memo := make([][][2]int, m)
	for i := range memo {
		memo[i] = make([][2]int, n)
		for j := range memo[i] {
			memo[i][j] = [2]int{-1, -1}
		}
	}
	memo[0][0][0], memo[0][0][1] = 1, 1
	var dfs func(int, int, int) int
	dfs = func(i, j, k int) int {
		if i < 0 || j < 0 || i >= m || j >= n {
			return 0
		}

		if memo[i][j][k] != -1 {
			return memo[i][j][k]
		}

		if grid[i][j] == 0 {
			memo[i][j][k] = (dfs(i, j-1, 0) + dfs(i-1, j, 1)) % mod
		} else {
			if k == 0 {
				memo[i][j][k] = dfs(i-1, j, 1)
			} else {
				memo[i][j][k] = dfs(i, j-1, 0)
			}
		}
		return memo[i][j][k]
	}
	return dfs(m-1, n-1, 0)
}