from typing import List

class Solution:
    def subsets(self, a: List[int]) -> List[List[int]]:
        def dfs(cur, a, i, ans):
            if i == len(a):
                ans.append(cur.copy())
                return 
            
            cur.append(a[i])
            dfs(cur, a, i+1, ans)
            cur.pop()
            dfs(cur, a, i+1, ans)

        ans = []
        dfs([], a, 0, ans)

        return ans
