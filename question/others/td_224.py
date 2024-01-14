'''

Given a string and a positive number `k`, find the longest substring of the string containing `k` distinct characters. If `k` is more than the total number of distinct characters in the string, return the whole string.

Input: s = 'abcbdbdbbdcdabd', k = 2
Output: 'bdbdbbd'

Input: s = 'abcbdbdbbdcdabd', k = 3
Output: 'bcbdbdbbdcd'

Input: s = 'abcbdbdbbdcdabd', k = 5
Output: 'abcbdbdbbdcdabd'

The longest distinct character substring is not guaranteed to be unique. If multiple longest distinct substring exists, the solution should return the one which appear first in the string.

Input: s = 'abcd", k = 3
Output: 'abc'
Explanation: There are two longest distinct substrings in 'abcd' having 3 distinct characters, namely, 'abc' and 'bcd". The solution returns 'abc' as it appears before 'bcd' in the string.

'''

from collections import defaultdict

class Solution:
    def findLongestSubstring(self, s: str, k: int) -> str:
        # Write your code here...
        d = defaultdict(int)
        l = 0
        ans = 0
        tl, tr = 0,0
        for r in range(len(s)):
            d[s[r]] += 1
            while len(d) > k:
                d[s[l]]-=1
                if d[s[l]] == 0:
                    del d[s[l]]
                l+=1
            if len(d) <= k:
                if r-l+1 > ans:
                    ans = r-l+1
                    tl, tr = l, r
        
        return s[tl:tr+1]