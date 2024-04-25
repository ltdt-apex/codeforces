from collections import defaultdict

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        l = 0
        d = defaultdict(int)

        for c in s1:
            d[c]+=1
        
        for r in range(len(s2)):
            d[s2[r]]-=1
            if d[s2[r]] == 0:
                del d[s2[r]]
            if r-l>=len(s1):
                d[s2[l]]+=1
                if d[s2[l]] == 0:
                    del d[s2[l]]
                l+=1

            if not d:
                return True
                
        return False