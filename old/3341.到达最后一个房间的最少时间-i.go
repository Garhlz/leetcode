/*
 * @lc app=leetcode.cn id=3341 lang=golang
 *
 * [3341] 到达最后一个房间的最少时间 I
 */

// @lc code=start
var dx = []struct{ x, y int }{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}

func minTimeToReach(mp [][]int) (ans int) {
	n, m := len(mp), len(mp[0])
	dis := make([][]int, n)
	for i := range dis { // 如果只有一个数字就是下标
		dis[i] = make([]int, m)
		for j := range dis[i] {
			dis[i][j] = math.MaxInt
		}
	}
	dis[0][0] = 0

	h := hp{{0, 0, 0}} // 空的堆
	for {
		top := heap.Pop(&h).(tuple)
		i, j := top.x, top.y
		if i == n-1 && j == m-1 {
			return top.dis
		}
		if top.dis > dis[i][j] {
			continue
		}
		for _, d := range dx {
			x, y := i+d.x, j+d.y
			if x >= 0 && x < n && y >= 0 && y < m {
				// d1 := max(top.dis, mp[x][y]) + (i+j)%2 + 1
				d1 := max(top.dis, mp[x][y]) + 1
				if d1 < dis[x][y] {
					dis[x][y] = d1
					heap.Push(&h, tuple{d1, x, y})
				}
			}
		}
	}
}

type tuple struct{ dis, x, y int }
type hp []tuple

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis }
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *hp) Push(v any)        { *h = append(*h, v.(tuple)) }
func (h *hp) Pop() (v any)      { a := *h; *h, v = a[:len(a)-1], a[len(a)-1]; return }

// @lc code=end

