/*
 * @lc app=leetcode.cn id=3112 lang=golang
 *
 * [3112] 访问消失节点的最少时间
 */

// @lc code=start
func minimumTime(n int, edges [][]int, disappear []int) []int {
	type edge struct{ to, w int }
	g := make([][]edge, n) // 邻接表，一开始只初始化了第一维
	for _, e := range edges {
		x, y, w := e[0], e[1], e[2]
		g[x] = append(g[x], edge{y, w})
		g[y] = append(g[y], edge{x, w})
	}

	dis := make([]int, n)
	for i := range dis {
		dis[i] = -1
	}
	dis[0] = 0

	h := hp{{}}
	for len(h) > 0 {
		p := heap.Pop(&h).(pair)
		dx, x := p.dis, p.x
		if dx > dis[x] {
			continue
		}
		for _, e := range g[x] {
			y := e.to
			newDis := dx + e.w
			if newDis < disappear[y] && (dis[y] < 0 || newDis < dis[y]) {
				dis[y] = newDis
				heap.Push(&h, pair{newDis, y})
			}
		}
	}
	return dis
}

type pair struct{ dis, x int }
type hp []pair

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(pair)) }
func (h *hp) Pop() (v any)      { a := *h; *h, v = a[:len(a)-1], a[len(a)-1]; return }

//写在同一行注意要分号
// @lc code=end

