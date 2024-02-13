from typing import List

class Solution:
    def returnToBoundaryCount(self, a: List[int]) -> int:
        c = 0
        ans = 0

        for n in a:
            c+=n
            if c==0:
                ans+=1

        return ans