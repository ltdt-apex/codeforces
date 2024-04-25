from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, ss: List[str]) -> List[List[str]]:
        d = defaultdict(list)
        for s in ss:
            d["".join(sorted(s))].append(s)

        return d.values()
            