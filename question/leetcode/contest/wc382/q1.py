class Solution:
    def countKeyChanges(self, s: str) -> int:
        last = None
        a = 0

        for c in s:
            if c.lower() != last:
                last = c.lower()
                a+=1

        return a - 1