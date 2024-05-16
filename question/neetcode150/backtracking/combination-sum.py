from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        ans = []

        s = []

        def dfs(remaining, i):
            if remaining == 0:
                ans.append(s.copy())
                return
            if i == len(candidates):
                return
            
            if remaining < 0:
                return 

            s.append(candidates[i])
            dfs(remaining-candidates[i], i)
            s.pop()

            dfs(remaining,i+1)

        dfs(target,0)
        return ans
