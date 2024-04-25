from collections import defaultdict
import math

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        l = 0
        d1 = defaultdict(int)
        for c in t:
            d1[c] += 1

        d2 = defaultdict(int)
        al, ar = -math.inf, math.inf
        have, need = 0, len(d1)

        for r,c in enumerate(s):
            d2[c] += 1
            if c in d1 and d1[c] == d2[c]:
                have += 1
            while have >= need:
                if r-l < ar-al:
                    al,ar = l,r
                c = s[l]
                if c in d1 and d2[c] == d1[c]:
                    have -= 1
                d2[c]-=1
                l+=1

        return s[al:ar+1] if al != -math.inf else ""