from typing import List
from collections import defaultdict

class Solution:
    def topKFrequent(self, a: List[int], k: int) -> List[int]:
        d = defaultdict(int)

        for n in a:
            d[n] += 1

        ans = [(v,i) for i,v in d.items()]
        ans.sort(reverse=True)

        ans = [ans[i][1] for i in range(k)]

        return ans