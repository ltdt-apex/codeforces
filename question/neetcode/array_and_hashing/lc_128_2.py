from typing import List
from collections import defaultdict

class Solution:
    def longestConsecutive(self, a: List[int]) -> int:
        ans = 0
        s = set(a)
        for l in s:
            if l-1 not in s:
                r = l
                while r+1 in s:
                    r+=1
                ans = max(ans, r-l+1)

        return ans
                