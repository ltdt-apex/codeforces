from typing import List

class Solution:
    def countMatchingSubarrays(self, a: List[int], p: List[int]) -> int:
        pre = []
        for i in range(1, len(a)):
            if a[i] > a[i-1]:
                pre.append(1)
            if a[i] == a[i-1]:
                pre.append(0) 
            if a[i] < a[i-1]:
                pre.append(-1)

        m = len(p)

        ans = 0
        for i in range(len(a)-1-m+1):
            ok = True
            for j in range(len(p)):
                if pre[i+j] != p[j]:
                    ok = False

            if ok:
                ans+=1
        
        return ans