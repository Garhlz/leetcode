func findOrder(n int, pre [][]int) []int {
	e := make([][]int, n)
	vis := make([]int, n)
	res := []int{}
	valid := true
    var dfs func(int)
	dfs = func(x int) {
		vis[x] = 1
		for _, y := range e[x] {
			if vis[y] == 0 {
				dfs(y)
				if !valid {
					return
				}
			} else if vis[y] == 1 {
				valid = false
				return
			}
		}
		vis[x] = 2
		res = append(res, x) // 逆序入队
	}

	for _, info := range pre {
		e[info[1]] = append(e[info[1]], info[0])
	}

	for i:=0;i < n && valid;i++{
		if(vis[i] == 0){
            dfs(i)
        }
	}
	if !valid {
		return []int{}
	}
	for i := 0;i < len(res) / 2;i++ {
		res[i],res[n-i-1] = res[n - i - 1],res[i]
	}
	return res
}
