from typing import List

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n = len(nums)
        ans = 0
        i = n
        while i>=1:
            while ans+i < n and nums[ans+i]<=target:
                ans+=i
            i//=2

        return ans if nums[ans] == target else -1