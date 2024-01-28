from collections import defaultdict
import math

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        ans = math.inf
        d = defaultdict(int)
        l = 0
        tl, tr = -1, -1

        for c in t:
            d[c] -= 1
        
        for r in range(len(s)):
            d[s[r]]+=1
            while d[s[l]] > 0 and l <= r:
                d[s[l]] -= 1
                l+=1
            
            if all(v >= 0 for v in d.values()):
                if r-l+1 < ans:
                    ans = r-l+1
                    tl, tr = l, r

        if ans == math.inf:
            return ""
        else:
            return s[tl:tr+1]
        