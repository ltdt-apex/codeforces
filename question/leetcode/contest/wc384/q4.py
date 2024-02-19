from typing import List

class Solution:
    def countMatchingSubarrays(self, a: List[int], p: List[int]) -> int:
        pre = []
        n = len(a)
        for i in range(1, n):
            if a[i] > a[i-1]:
                pre.append(1)
            if a[i] == a[i-1]:
                pre.append(0) 
            if a[i] < a[i-1]:
                pre.append(-1)

        p.append(2)

        dp = [0]
        for i in range(1,len(p)):
            j = dp[i-1]
            while j and p[j] != p[i]:
                j = dp[j-1]
            if p[j] == p[i]:
                j+=1
            dp.append(j)
        
        # print(p)
        # print(dp)

        ans = 0
        j = 0
        for i in range(len(pre)):
            while j and p[j] != pre[i]:
                j = dp[j-1]
            if p[j] == pre[i]:
                j+=1
            # print(j, end=" ")
            if j == len(p)-1:
                ans+=1
        # print(ans)

        return ans