func watchedVideosByFriends(watchedVideos [][]string, friends [][]int, id int, level int) []string {

	n := len(friends)
	q := []int{id}
	dep := make([]int, n)
	vis := make([]bool, n)
	set := []int{}
	dep[id] = 0
	vis[id] = true
	for len(q) > 0 {
		x := q[0]
		q = q[1:]
		for _, y := range friends[x] {
			if vis[y] == true {
				continue
			}
			vis[y] = true
			dep[y] = dep[x] + 1
			q = append(q, y)
			if dep[y] == level {
				set = append(set, y)
			}
		}
	}
	fre := make(map[string]int)
	for _, x := range set {
		for _, y := range watchedVideos[x] {
			fre[y]++
		}
	}
	return sortItem(fre)
}

func sortItem(items map[string]int) []string {
	itemsList := make([]struct {
		name  string
		count int
	}, 0, len(items))

	for name, count := range items {
		itemsList = append(itemsList, struct {
			name  string
			count int
		}{name, count})
	}

	sort.Slice(itemsList, func(i, j int) bool {
		if itemsList[i].count == itemsList[j].count {
			return itemsList[i].name < itemsList[j].name
		}
		return itemsList[i].count < itemsList[j].count
	})

	res := make([]string, len(itemsList))
	for i, item := range itemsList {
		res[i] = item.name
	}
	return res
}