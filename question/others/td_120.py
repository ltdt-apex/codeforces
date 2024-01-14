'''

Given an integer array, find all maximum size contiguous subarrays having all distinct elements in them.

Input : [5, 2, 3, 5, 4, 3]
Output: {(5, 2, 3), (2, 3, 5, 4), (5, 4, 3)}

Input : [1, 2, 3, 3]
Output: {(1, 2, 3), (3)}

Input : [1, 2, 3, 4]
Output: {(1, 2, 3, 4)}

Note: Since an input can have multiple subarrays with all distinct elements, the solution should return a set containing all the distinct subarrays.

'''

from typing import List, Set, Tuple
from collections import defaultdict

class Solution:
    def findDistinctSubarrays(self, nums: List[int]) -> Set[Tuple[int]]:
        s = set()
        
        d = defaultdict(int)

        l = 0
        for r in range(len(nums)):
            if d[nums[r]] == 1:
                s.add(tuple(nums[l:r]))
            d[nums[r]] += 1
            while d[nums[r]] > 1:
                d[nums[l]] -= 1
                l+=1
        
        if len(nums)!=0:
            s.add(tuple(nums[l:]))
        return s