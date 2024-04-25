class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        l = 0
        n = len(s)

        d = set()
        ans = 0
        for r in range(n):
            while s[r] in d:
                d.remove(s[l])
                l+=1
            d.add(s[r])
            ans = max(ans, r-l)
        
        return ans