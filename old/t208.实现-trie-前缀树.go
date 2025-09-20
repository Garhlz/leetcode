/*
 * @lc app=leetcode.cn id=208 lang=golang
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start
type Node struct {
	son [26]*Node
	end bool
}

type Trie struct {
	root *Node
}

func Constructor() Trie {
	return Trie{&Node{}}
}

func (this *Trie) Insert(word string) {
	now := this.root
	for _, c := range word {
		c -= 'a'
		if now.son[c] == nil {
			now.son[c] = &Node{}
		}
		now = now.son[c]
	}
	now.end = true
}

func (t Trie) find(s string) int {
	now := t.root
	for _, c := range s {
		c -= 'a'
		if now.son[c] == nil {
			return 0
		}
		now = now.son[c]
	}
	if now.end {
		return 2
	}
	return 1
}

func (this *Trie) Search(word string) bool {
	return this.find(word) == 2
}

func (this *Trie) StartsWith(prefix string) bool {
	return this.find(prefix) != 0
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */
// @lc code=end

