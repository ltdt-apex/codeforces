from collections import defaultdict

class Trie:
    def __init__(self):
        self.child = defaultdict(Trie)
        self.end = False

class WordDictionary:

    def __init__(self):
        self.root = Trie()

    def addWord(self, word: str) -> None:
        node = self.root
        for c in word:
            node = node.child[c]
        node.end=True

    def search(self, word: str) -> bool:
        def dfs(i, node):
            if i == len(word):
                return node.end
            
            if word[i] == ".":
                for next in node.child.values():
                    if dfs(i+1, next):
                        return True
                return False
            else:
                if word[i] not in node.child:
                    return False
                
                return dfs(i+1,node.child[word[i]])

        return dfs(0, self.root)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)