from collections import defaultdict

class Solution:
    def isAnagram(self, a: str, b: str) -> bool:
        d = defaultdict(int)

        for n in a:
            d[n] += 1

        for n in b:
            d[n] -= 1

        for n in d.values():
            if n != 0:
                return False
            
        return True