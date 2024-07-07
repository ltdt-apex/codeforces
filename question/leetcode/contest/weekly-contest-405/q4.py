from typing import List
import math
from collections import defaultdict

class Trie:
    def __init__(self):
        self.score = math.inf
        self.node = defaultdict(Trie)

class Solution:
    def minimumCost(self, target: str, words: List[str], costs: List[int]) -> int:
        trie = Trie()
        n = len(target)

        for word,cost in zip(words, costs):
            cur = trie
            for char in reversed(word):
                cur = cur.node[char]
            cur.score = min(cur.score, cost)

        dp = [0] + [math.inf for _ in range(n)]

        for i in range(n):
            cur = trie
            for j in range(i,-1,-1):
                if target[j] not in cur.node:
                    break
                cur = cur.node[target[j]]
                dp[i+1] = min(dp[i+1], dp[j] + cur.score)

        return dp[-1] if dp[-1] != math.inf else -1

