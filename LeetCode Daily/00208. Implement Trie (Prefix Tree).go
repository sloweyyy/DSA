type Trie struct {
	children [26]*Trie
	terminal bool
}

func Constructor() Trie { return Trie{} }
func (trie *Trie) Insert(word string) {
	node := trie
	for i := 0; i < len(word); i++ {
		index := word[i] - 'a'
		if node.children[index] == nil {
			node.children[index] = &Trie{}
		}
		node = node.children[index]
	}
	node.terminal = true
}
func (trie *Trie) walk(prefix string) *Trie {
	node := trie
	for i := 0; i < len(prefix); i++ {
		node = node.children[prefix[i]-'a']
		if node == nil {
			return nil
		}
	}
	return node
}
func (trie *Trie) Search(word string) bool {
	node := trie.walk(word)
	return node != nil && node.terminal
}
func (trie *Trie) StartsWith(prefix string) bool { return trie.walk(prefix) != nil }
