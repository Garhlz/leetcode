func findAllRecipes(recipes []string, ingredients [][]string, q []string) []string {
	g := map[string][]string{}
	in := make(map[string]int, len(recipes))
	for i, r := range recipes {
		for _, s := range ingredients[i] {
			g[s] = append(g[s], r)
		}
		in[r] = len(ingredients[i])
	}
	ans := []string{}
	for len(q) > 0 {
		s := q[0]
		q = q[1:]
		for _, r := range g[s] {
			in[r]-- // 仅计算直接入度,此处表示一种菜是可达的
			if in[r] == 0 {
				q = append(q, r)
				ans = append(ans, r)
			}
		}
	}
	return ans
}