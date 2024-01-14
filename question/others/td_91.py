'''

Given an array of positive integers and a positive integer k, find the smallest contiguous subarray length whose sum of elements is greater than k.

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 7
Output: 1
Explanation: The smallest subarray with sum > 20 is [8]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 20
Output: 3
Explanation: The smallest subarray with sum > 20 is [6, 7, 8]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 21
Output: 4
Explanation: The smallest subarray with sum > 20 is [4, 5, 6, 7]

Input : [1, 2, 3, 4, 5, 6, 7, 8], k = 40
Output: 0
Explanation: No subarray exists

'''
import math
from typing import List

class Solution:
    def findSmallestSubarray(self, nums: List[int], k: int) -> int:
        # Write your code here...

        l = 0
        ans = math.inf
        cur = 0

        for r in range(len(nums)):
            cur += nums[r] 
            while cur > k:
                if cur - nums[l] <= k:
                    break
                cur -= nums[l]
                l += 1

            if cur > k:
                ans = min(ans, r-l+1)

        if ans == math.inf:
            return 0
        else:
            return ans

