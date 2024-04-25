from typing import List

class Solution:
    def twoSum(self, a: List[int], t: int) -> List[int]:
        l = 0
        r = len(a)-1

        while True:
            if a[l]+a[r] > t:
                r-=1
            elif a[l]+a[r] < t:
                l+=1
            else:
                return l+1,r+1