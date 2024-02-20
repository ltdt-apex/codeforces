from typing import List

class Solution:
    def maxOperations(self, a: List[int]) -> int:
        n = len(a)

        p = a[0]+a[1]

        i = 0
        while i<n//2:
            if a[i*2] + a[i*2+1] != p:
                break
            i+=1

        return i
            
    
        