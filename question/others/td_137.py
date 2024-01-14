'''

Given an integer array and a positive number `k`, check whether the array contains any duplicate elements within the range `k`. If `k` is more than the array’s size, the solution should check for duplicates in the complete array.

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 4
Output: True
Explanation: Element 6 repeats at distance 4 which is <= k

Input: nums[] = [5, 6, 8, 2, 4, 6, 9], k = 2
Output: False
Explanation: Element 6 repeats at distance 4 which is > k

Input: nums[] = [1, 2, 3, 2, 1], k = 7
Output: True
Explanation: Element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k

'''

from typing import List

class Solution:
    def hasDuplicate(self, nums: List[int], k: int) -> bool:
        # Write your code here...
        d = dict()

        for i,n in enumerate(nums):
            if n in d:
                if i-d[n] <= k or k > len(nums):
                    return True 
            d[n] = i

        return False