from collections import defaultdict

class Solution:
    def characterReplacement(self, a: str, k: int) -> int:
        n = len(a)
        ans = 0 
        l = 0
        d = defaultdict(int)

        for r in range(n):
            d[a[r]] += 1

            while r-l+1 > max(d.values()) + k:
                d[a[l]]-=1
                l+=1

            ans = max(ans, r-l+1)

        return ans