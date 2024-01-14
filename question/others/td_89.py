'''

Given an integer array, find a contiguous subarray having sum `k` in it where `k` is an integer.

Input : nums[] = [2, 6, 0, 9, 7, 3, 1, 4, 1, 10], k = 15
Output: [6, 0, 9]

Input : nums[] = [0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10], k = -3
Output: [1, -4] or [-7, 1, -4, 7]

Note: Since an input can contain several subarrays having sum `k`, the solution can return any one of them.

Input : nums[] = [0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10], k = 15
Output: [1, -4, 7, 6, 1, 4] or [4, 1, 10]

'''

from typing import List
from itertools import accumulate
from collections import defaultdict

class Solution:
    def findSubarray(self, nums: List[int], k: int) -> List[int]:
        # Write your code here...
        p = [0] + list(accumulate(nums))
        
        d = defaultdict(int)

        for r,n in enumerate(p):
            if n - k in d:
                l = d[n-k]
                return nums[l:r]
            else:
                d[n] = r

        return []