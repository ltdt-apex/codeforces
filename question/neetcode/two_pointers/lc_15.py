from collections import defaultdict
from typing import List

class Solution:
    def threeSum(self, a: List[int]) -> List[List[int]]:
        ans = set()
        n = len(a)
        for i in range(n):
            s = set()
            for j in range(i+1, n):
                c = -(a[i] + a[j])
                if c in s:
                    ans.add(tuple(sorted([a[i],a[j],c])))
                s.add(a[j])

        return list(ans)