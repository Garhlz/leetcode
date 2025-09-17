/*
 * @lc app=leetcode.cn id=743 lang=golang
 *
 * [743] 网络延迟时间
 */

// @lc code=start
func networkDelayTime(times [][]int, n int, k int) int {
	type edge struct{ to, wt int }
	g := make([][]edge, n)
	for _, t := range times {
		g[t[0]-1] = append(g[t[0]-1], edge{t[1] - 1, t[2]})
		//存储指向的点和长度
	}
	dis := make([]int, n)
	for i := range dis {
		dis[i] = math.MaxInt
		//注意
	}
	dis[k-1] = 0
	h := hp{{0, k - 1}} // 相当于构造函数,h是堆本体

	for len(h) > 0 {
		p := heap.Pop(&h).(pair)
		dx, x := p.dis, p.x
		if dx > dis[x] {
			continue
		}
		for _, e := range g[x] {
			y := e.to
			if dx+e.wt < dis[y] {
				dis[y] = dx + e.wt
				heap.Push(&h, pair{dis[y], y})
			}
		}
	}
	mx := slices.Max(dis)
	if mx < math.MaxInt {
		return mx
	} else {
		return -1
	}
}

type pair struct{ dis, x int }

type hp []pair

func (h hp) Len() int {
	return len(h)
}

func (h hp) Less(i, j int) bool {
	return h[i].dis < h[j].dis
}

func (h hp) Swap(i, j int) {
	h[i], h[j] = h[j], h[i]
}

func (h *hp) Push(v any) {
	*h = append(*h, v.(pair))
}

func (h *hp) Pop() any {
	a := *h
	var v any
	*h, v = a[:len(a)-1], a[len(a)-1]
	return v
}

// @lc code=end

