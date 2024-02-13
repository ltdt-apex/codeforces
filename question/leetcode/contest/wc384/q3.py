from typing import List
from collections import defaultdict

class Solution:
    def maxPalindromesAfterOperations(self, a: List[str]) -> int:
        l = [len(i) for i in a]

        l.sort()

        d = defaultdict(int)
        for s in a:
            for c in s:
                d[c] += 1

        ans = 0

        for n in l:
            nd = n-n%2
            ns = n%2

            for c in d:
                if d[c] >= 2:
                    sub = min(nd, d[c]-d[c]%2)
                    d[c] -= sub
                    nd -= sub
                if nd == 0:
                    break
            
            if nd != 0:
                break

            if ns == 0:
                ans+=1
                continue

            for c in d:
                if d[c]%2==1:
                    ns = 0
                    d[c]-=1
            
            if ns!=0:
                for c in d:
                    if d[c]>0:
                        ns=0
                        d[c]-=1

            if ns!=0:
                break

            ans+=1

        return ans