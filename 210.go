package main

import "fmt"

func findOrder(n int, prerequisites [][]int) []int {
	v := make([][]int, n)
	in := make([]int, n) // 记录入度
	for i := range v {
		v[i] = []int{} //初始化为空
	}
	for _, e := range prerequisites {
		a, b := e[0], e[1]
		v[b] = append(v[b], a)
		in[b]++
	}
	var root int
	for i, x := range in { // 找到入度=0的点
		if x == 0 {
			root = i
			break
		}
	}

	vis := make([]bool, n)
	stk := []int{}
	return dfs(n, root, 1, vis, v, &stk)
}

func dfs(n int, x int, num int, vis []bool, v [][]int, stk *[]int) []int {
	if num == n {
		return *stk
	}
	for _, y := range v[x] {
		if vis[y] == true {
			continue
		}
		*stk = append(*stk, y)
		vis[y] = true
		dfs(n, y, num+1, vis, v, stk)
		*stk = (*stk)[:len(*stk)-1]
		vis[y] = false
	}
	return []int{}
}

func main() {
	numCourses := 4
	prerequisites := [][]int{{1, 0}, {2, 0}, {3, 1}, {3, 2}}
	fmt.Println(findOrder(numCourses, prerequisites))
}
