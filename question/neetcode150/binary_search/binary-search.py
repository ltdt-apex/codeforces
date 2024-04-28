from typing import List

class Solution:
    def search(self, a: List[int], t: int) -> int:
        i = 0
        n = len(a)
        while n:
            while i+n < len(a) and a[i+n] < t:
                i+=n
            n//=2

        return -1 if a[i] != t else i