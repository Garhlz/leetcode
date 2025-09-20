/*
 * @lc app=leetcode.cn id=211 lang=golang
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
type Node struct {
	son [26]*Node
	end bool
}

func (t *Node) Insert(word string) {
	node := t
	for _, ch := range word {
		ch -= 'a'
		if node.son[ch] == nil {
			node.son[ch] = &Node{}
		}
		node = node.son[ch]
	}
	node.end = true
}

type WordDictionary struct {
	root *Node
}

func Constructor() WordDictionary {
	return WordDictionary{&Node{}}
}

func (this *WordDictionary) AddWord(word string) {
	this.root.Insert(word)
}

func (this *WordDictionary) Search(word string) bool {
	var dfs func(int, *Node) bool // 递归调用的临时函数必须要先声明
	dfs = func(index int, node *Node) bool {
		if index == len(word) {
			return node.end
		}
		ch := word[index]
		if ch != '.' {
			son := node.son[ch-'a']
			if son != nil && dfs(index+1, son) {
				return true
			}
		} else {
			for i := range node.son {
				son := node.son[i]
				if son != nil && dfs(index+1, son) {
					return true
				}
			}
		}
		return false
	}
	return dfs(0, this.root)
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
// @lc code=end

