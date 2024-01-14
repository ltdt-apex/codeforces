'''

Given a binary array and a positive integer `k`, return the indices of the maximum sequence of continuous 1’s that can be formed by replacing at most `k` zeroes by ones.

• The solution should return a pair of the starting and the ending index of the maximum sequence.
• For invalid inputs, the solution should return an empty tuple.
• In case multiple sequence of continuous 1’s of maximum length exists, the solution can return any one of them.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 0
Output: (6, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 6 to 9.

Input : nums[] = [1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0], k = 1
Output: (3, 9)
Explanation: The longest sequence of continuous 1’s is formed by index 3 to 9 on replacing zero at index 5.

Input : nums[] = [1, 1, 1, 1, 1], k = 1
Output: (0, 4)

Input : nums[] = [1, 0, 1, 1, 0, 0, 1, 1, 0, 1], k = 1
Output: (0, 3) or (6, 9)

Input : nums[] = [], k = 1
Output: ()

'''

from typing import List, Tuple
from collections import defaultdict


class Solution:
    def findLongestSequence(self, nums: List[int], k: int) -> Tuple[int]:    
        d =defaultdict(int)
        ans = 0
        tl,tr = 0,0

        if len(nums) == 0:
            return ()

        l = 0
        for r in range(len(nums)):
            d[nums[r]] += 1

            while d[0] > k:
                d[nums[l]] -= 1
                l+=1

            if r-l+1 > ans:
                ans = r-l+1
                tl, tr = l, r

        return (tl, tr)

