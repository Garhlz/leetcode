package main

import (
	"container/heap"
	"math"
)

// --- 结构体与堆实现部分 ---

//  1. pair 结构体: 用于存储在优先队列（堆）中的元素。
//     它将节点的距离(dis)和节点编号(x)绑定在一起。
type pair struct{ dis, x int }

//  2. hp 类型: 定义了堆的底层数据结构，它本质上是一个 pair 类型的切片。
//     hp 是 heap 的缩写。
type hp []pair

// 以下五个方法是为 hp 类型实现 heap.Interface 接口，
// 这样 container/heap 包里的算法就能在我们的 hp 上工作了。

func (h hp) Len() int           { return len(h) }
func (h hp) Less(i, j int) bool { return h[i].dis < h[j].dis } // dis 小的优先级高（最小堆）
func (h hp) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }

// Push 和 Pop 方法需要使用指针接收者 (*hp)，因为它们会修改切片的长度。
func (h *hp) Push(v any) { *h = append(*h, v.(pair)) }
func (h *hp) Pop() (v any) {
	a := *h
	*h, v = a[:len(a)-1], a[len(a)-1]
	return
}

// --- 核心算法函数 ---

func minCost(n int, edges [][]int) int {
	// 3. edge 结构体: 这是一个在函数内部定义的局部类型。
	//    用于清晰地表示图的一条边，包含终点(to)和权重(wt)。
	type edge struct{ to, wt int }

	g := make([][]edge, n) // 使用邻接表来表示图
	for _, e := range edges {
		x, y, wt := e[0], e[1], e[2]
		g[x] = append(g[x], edge{y, wt})
		g[y] = append(g[y], edge{x, wt * 2}) // 根据题目逻辑添加反向边
	}

	dis := make([]int, n)
	for i := range dis {
		dis[i] = math.MaxInt
	}
	dis[0] = 0

	// 初始化一个指向 hp 切片的指针，并将起点 {0, 0} 放入
	h := &hp{{}}

	for h.Len() > 0 {
		p := heap.Pop(h).(pair)
		disX, x := p.dis, p.x
		if disX > dis[x] {
			continue
		}
		if x == n-1 { // 提前退出优化
			return disX
		}

		for _, e := range g[x] {
			y := e.to
			newDisY := disX + e.wt
			if newDisY < dis[y] {
				dis[y] = newDisY
				heap.Push(h, pair{newDisY, y})
			}
		}
	}

	return -1
}

// --- 程序入口 ---

// func main() {
// 	// 定义一个测试用的图
// 	// n 是节点数量
// 	n := 4
// 	// edges 是边的列表，格式为 [起点, 终点, 权重]
// 	edges := [][]int{
// 		{0, 1, 10},
// 		{0, 2, 20},
// 		{1, 3, 5},
// 		{2, 3, 5},
// 	}

// 	fmt.Printf("图有 %d 个节点。\n", n)
// 	fmt.Println("边的信息:", edges)

// 	// 调用算法函数计算从节点 0 到节点 n-1 的最小代价
// 	cost := minCost(n, edges)

// 	if cost != -1 {
// 		fmt.Printf("从节点 0 到节点 %d 的最小代价是: %d\n", n-1, cost)
// 	} else {
// 		fmt.Printf("从节点 0 无法到达节点 %d\n", n-1)
// 	}
// }
