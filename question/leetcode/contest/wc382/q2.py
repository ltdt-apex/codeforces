from typing import *
from collections import defaultdict

class Solution:
    def maximumLength(self, a: List[int]) -> int:
        d = defaultdict(int)
        ans = defaultdict(int)

        for n in a:
            d[n]+=1
        
        a = sorted(list(set(a) - {1})) 

        for n in a:
            if d[n] >= 2 and d[n*n] >= 1:
                ans[n*n] = ans[n] + 2

        ans[0] = 0

        ans1 = d[1] if d[1]%2 else d[1] - 1

        return max(max(ans.values()) + 1, ans1)