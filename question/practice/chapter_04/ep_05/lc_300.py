from typing import List
import math
import bisect

class Solution:
    def lengthOfLIS(self, a: List[int]) -> int:
        n = len(a)

        dp = []

        for x in a:
            i = bisect.bisect_left(dp, x)
            if i == len(dp):
                dp.append(x)
            else:
                dp[i] = x

        return len(dp)
