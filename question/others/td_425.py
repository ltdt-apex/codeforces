'''

Given an integer array and a positive integer `k`, find the minimum sum contiguous subarray of size `k`.

Input : nums[] = [10, 4, 2, 5, 6, 3, 8, 1], k = 3
Output: [4, 2, 5]

Input : nums[] = [1, 4, 5, 3, 8], k = 6
Output: [1, 4, 5, 3, 8]

Note: Since an input can contain several minimum sum subarrays of size `k`, the solution can return any one of them.

'''
from typing import List
import math

class Solution:
    def findMinSumSubarray(self, nums: List[int], k: int) -> List[int]:
        # Write your code here...
        ans,tl,tr = math.inf,0,0

        if k > len(nums):
            return nums
        
        cur = 0
        for r in range(len(nums)):
            cur += nums[r]
            l = r-k
            if l >= 0:
                cur-=nums[l]
            if r>=k-1 and cur < ans:
                ans = cur
                tl,tr = l+1, r

        return nums[tl:tr+1]

