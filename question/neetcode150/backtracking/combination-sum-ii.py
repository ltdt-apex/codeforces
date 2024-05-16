from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()

        ans = []

        s = []

        def dfs(i, r):
            if r == 0 and i == len(candidates):
                ans.append(s.copy())
            if r < 0:
                return
            if i == len(candidates):
                return
            
            s.append(candidates[i])
            dfs(i+1,r-candidates[i])
            s.pop()

            while i+1 < len(candidates):
                if candidates[i] != candidates[i+1]:
                    break
                i+=1
            dfs(i+1,r)

        dfs(0, target)
        return ans