from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = set()

        s = []

        def dfs(i):
            if i==len(nums):
                # print(tuple(sorted(s)))
                ans.add(tuple(sorted(s)))
                return

            s.append(nums[i])
            dfs(i+1)
            s.pop()
            dfs(i+1)

        dfs(0)
        return [list(s) for s in ans]
