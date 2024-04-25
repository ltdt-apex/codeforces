from collections import defaultdict

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        d = defaultdict(int)

        for c in s:
            d[c] += 1

        for c in t:
            d[c] -= 1

        for n in d.values():
            if n != 0:
                return False
            

        return True