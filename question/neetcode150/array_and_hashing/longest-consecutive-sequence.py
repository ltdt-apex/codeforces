from typing import List

class Solution:
    def longestConsecutive(self, a: List[int]) -> int:
        s = set(a)

        ans = 0
        for n in s:
            if n-1 in s:
                continue
            
            i = 0
            while n+i in s:
                ans = max(ans, i+1)
                i+=1

        return ans
