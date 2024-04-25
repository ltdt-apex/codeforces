from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, a: List[int], k: int) -> List[int]:
        d = defaultdict(int)
        for n in a:
            d[n] += 1

        count = [[] for _ in range(len(a)+1)]

        for n,c in d.items():
            count[c].append(n)

        ans = []

        for i in range(len(count)-1,-1,-1):
            ans.extend(count[i])
            if len(ans) == k:
                return ans
        