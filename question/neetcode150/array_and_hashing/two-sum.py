from typing import List

class Solution:
    def twoSum(self, a: List[int], t: int) -> List[int]:
        d = dict()

        for i,n in enumerate(a):
            if t - n in d:
                return [i,d[t-n]]
            d[n] = i