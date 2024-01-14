'''

Given a binary array, find the index of 0 to be replaced with 1 to get the maximum length sequence of continuous ones. The solution should return the index of first occurence of 0, when multiple continuous sequence of maximum length is possible.

Input : [0, 0, 1, 0, 1, 1, 1, 0, 1, 1]
Output: 7
Explanation: Replace index 7 to get the continuous sequence of length 6 containing all 1’s.

Input : [0, 1, 1, 0, 0]
Output: 0
Explanation: Replace index 0 or 3 to get the continuous sequence of length 3 containing all 1’s. The solution should return the first occurence.

Input : [1, 1]
Output: -1
Explanation: Invalid Input (all 1’s)

'''
from typing import List
from collections import defaultdict

class Solution:
    def findIndexofZero(self, nums: List[int]) -> int:
        # Write your code here...

        d =defaultdict(int)
        ans = 0
        ind = -1
        last = -1

        l = 0
        for r in range(len(nums)):
            d[nums[r]] += 1

            if nums[r] == 0:
                last = r

            while d[0] > 1:
                d[nums[l]] -= 1
                l+=1

            if r-l+1 > ans:
                ans = r-l+1
                ind = last

        return ind


