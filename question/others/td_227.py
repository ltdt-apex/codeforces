'''

Given two strings, find all substrings of the first string that are anagrams of the second string and return the list of their indices.

Two words, X and Y, are anagrams if by rearranging the letters of X, we can get Y using all the original letters of X exactly once.

Input: X = 'XYYZXZYZXXYZ', Y = 'XYZ'
Output: [2, 4, 6, 9]

Explanation:

Anagram 'YZX' present at index 2
Anagram 'XZY' present at index 4
Anagram 'YZX' present at index 6
Anagram 'XYZ' present at index 9

Note: The solution should return the indices in ascending order.

'''

from typing import List
from collections import defaultdict

class Solution:
    def findAllAnagrams(self, x: str, y: str) -> List[int]:
        # Write your code here...
        
        d = defaultdict(int)
        ans = []

        if len(y) == 0:
            return list(range(len(x)+1))

        for c in y:
            d[c] -= 1

        for r in range(len(x)):
            l = r - len(y)

            d[x[r]] += 1
            if d[x[r]] == 0:
                del d[x[r]]

            if l >= 0:
                d[x[l]] -= 1
                if d[x[l]] == 0:
                    del d[x[l]]

            if len(d) == 0:
                ans.append(l+1)
        
        return ans


            
