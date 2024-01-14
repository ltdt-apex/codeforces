'''

Given an array of sorted integers that may contain several duplicate elements, count the total number of distinct absolute values in it.

Input : [-1, -1, 0, 1, 1, 1]
Output: 2
Explanation: There are 2 distinct absolutes in the array [0, 1]

Input : [-2, -1, 0, 1, 2, 3]
Output: 4
Explanation: There are 4 distinct absolutes in the array [0, 1, 2, 3]

Input : [-1, -1, -1, -1]
Output: 1
Explanation: There is only 1 distinct absolute in the array [1]

'''

from typing import List

class Solution:
    def findDistinctCount(self, nums: List[int]) -> int:
        # Write your code here...
        
        s = set()

        for n in nums:
            s.add(abs(n))

        return len(s)


