'''

Given a string, find the longest substring containing distinct characters.

Input : 'longestsubstr'
Output: 'longest'

Input : 'abbcdafeegh'
Output: 'bcdafe'

Input : 'aaaaaa'
Output: 'a'

The longest distinct character substring is not guaranteed to be unique. If multiple longest distinct substring exists, the solution should return the one which appear first in the string.

Input: 'cbabc'
Output: 'cba'
Explanation: There are two longest distinct substrings in 'cbaabc' of length 3, namely, 'cba' and 'abc'. The solution returns 'cba' as it appears before 'abc' in the string.

'''
from collections import defaultdict

class Solution:
    def findLongestSubstring(self, s: str) -> str:
        # Write your code here...
        ans,tl,tr = 0,0,0
        n = len(s)
        d = defaultdict(int)

        l = 0
        for r in range(n):
            d[s[r]] += 1
            while d[s[r]] > 1:
                d[s[l]] -= 1
                l+=1
            if r-l+1 > ans:
                ans = r-l+1
                tl, tr = l,r 

        return s[tl:tr+1]