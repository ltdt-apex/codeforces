from collections import defaultdict

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        ans = 0
        d = defaultdict(int)
        for r in range(len(s)):
            d[s[r]]+=1
            while d[s[r]] > 1:
                d[s[l]] -= 1
                l+=1
            ans = max(ans, r-l+1)

        return ans