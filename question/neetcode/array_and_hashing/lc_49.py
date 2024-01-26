from typing import List
from collections import defaultdict

class Solution:
    def groupAnagrams(self, a: List[str]) -> List[List[str]]:
        ans = defaultdict(list)

        for s in a:
            cs = [0]*26
            for c in s:
                cs[ord(c) - ord("a")] += 1

            ans[tuple(cs)].append(s)

        return ans.values()

