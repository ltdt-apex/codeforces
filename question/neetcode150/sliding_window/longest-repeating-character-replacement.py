from collections import defaultdict

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        d = defaultdict(int)

        l = 0
        m = 0
        for r in range(len(s)):
            d[s[r]] += 1
            m = max(m, d[s[r]])

            if r-l+1 > k + m:
                d[s[l]] -= 1
                l+=1
        
        return m
