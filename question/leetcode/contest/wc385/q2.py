from collections import defaultdict

class Solution:
    def lastNonEmptyString(self, s: str) -> str:
        d = defaultdict(int)

        for c in s:
            d[c] += 1

        mv = max(d.values())

        ans = ""

        d2 = defaultdict(int)

        for c in s:
            d2[c]+=1
            if d2[c] == mv:
                ans+=c

        return ans