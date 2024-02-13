class Solution:
    def minimumTimeToInitialState(self, s: str, k: int) -> int:
        count = 0
        n = len(s)
        count += k
        while count < n:
            ok = True
            for a,b in zip(s,s[count:]):
                if a != b:
                    ok = False
            if ok:
                return count//k
            count+=k
            
        return count//k