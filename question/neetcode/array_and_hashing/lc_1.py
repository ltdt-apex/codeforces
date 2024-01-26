from typing import List
from collections import defaultdict


class Solution:
    def twoSum(self, a: List[int], s: int) -> List[int]:
        d = defaultdict(int)
        
        for i,n in enumerate(a):
            if s-n in d:
                return [i, d[s-n]]
            d[n] = i