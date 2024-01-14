'''

Given an integer array and a positive integer `k`, find the count of distinct elements in every contiguous subarray of size `k`.

Input : nums[] = [2, 1, 2, 3, 2, 1, 4, 5], k = 5
Output: [3, 3, 4, 5]
Explanation:

The count of distinct elements in subarray [2, 1, 2, 3, 2] is 3
The count of distinct elements in subarray [1, 2, 3, 2, 1] is 3
The count of distinct elements in subarray [2, 3, 2, 1, 4] is 4
The count of distinct elements in subarray [3, 2, 1, 4, 5] is 5


Input : nums[] = [1, 1, 2, 1, 3], k = 3
Output: [2, 2, 3]
Explanation:

The count of distinct elements in subarray [1, 1, 2] is 2
The count of distinct elements in subarray [1, 2, 1] is 2
The count of distinct elements in subarray [2, 1, 3] is 3

'''

from typing import List
from collections import defaultdict

class Solution:
    def findDistinctCount(self, nums: List[int], k: int) -> List[int]:
        # Write your code here...

        d = defaultdict(int)
        ans = []

        for r in range(len(nums)):
            d[nums[r]] += 1
            l = r - k
            if l >= 0:
                d[nums[l]] -= 1
                if d[nums[l]] == 0:
                    del d[nums[l]]
            if r >= k-1:
                ans.append(len(d))


        return ans