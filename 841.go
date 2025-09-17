
func canVisitAllRooms(rooms [][]int) bool {
	n := len(rooms)
	num := 0
	vis = make([]bool, n)
	var dfs func([][]int, int)
	dfs = func(rooms [][]int, x int) {
		vis[x] = true
		num++
		for _, y := range rooms[x] {
			if !vis[y] {
				dfs(rooms, y)
			}
		}
	}
	dfs(rooms, 0)
	return num == n
}