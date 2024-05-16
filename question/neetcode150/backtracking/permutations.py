from typing import List

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []

        if len(nums) == 1:
            return [nums.copy()]

        for _ in range(len(nums)):
            n = nums.pop(0)
            perms = self.permute(nums)

            for perm in perms:
                perm.append(n)
            ans.extend(perms)
            nums.append(n)

        return ans