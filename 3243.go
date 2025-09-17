func shortestDistanceAfterQueries(n int, queries [][]int) []int {
	mp := make([][]int, n)
	for i := 0; i < n-1; i++ {
		mp[i] = append(mp[i], i+1)
	}
	var ret []int
	bfs := func(n int, mp [][]int) int {
		dis := make([]int, n)
		for i := 1; i < n; i++ {
			dis[i] = -1
		}
		q := []int{0}
		for len(q) > 0 {
			x := q[0]
			q = q[1:]
			for _, y := range mp[x] {
				if dis[y] >= 0 {
					continue
				}
				dis[y] = dis[x] + 1
				q = append(q, y)
			}
		}
		return dis[n-1]
	}
	for _, query := range queries {
		mp[query[0]] = append(mp[query[0]], query[1])
		now := bfs(n, mp)
		res = append(res, now)
	}
	return res
}