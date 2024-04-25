from typing import List

class Solution:
    def trap(self, a: List[int]) -> int:
        n = len(a)

        l,r = 0,n-1

        lm = a[l]
        rm = a[r]
        ans = 0
        while l < r:
            if lm < rm:
                l+=1
                lm = max(lm, a[l])
                ans += lm - a[l]
            else:
                r-=1
                rm = max(rm, a[r])
                ans += rm - a[r]

        return ans