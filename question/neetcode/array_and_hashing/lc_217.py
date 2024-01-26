from typing import List
from collections import defaultdict

class Solution:
    def containsDuplicate(self, a: List[int]) -> bool:
        d = defaultdict(int)

        for n in a:
            d[n] += 1

        for v in d.values():
            if v > 1:
                return True
            
        return False