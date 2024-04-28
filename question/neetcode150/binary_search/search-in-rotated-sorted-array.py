from typing import List

class Solution:
    def search(self, a: List[int], t: int) -> int:
        f = a[0]

        if f <= t:
            i = 0
            n = len(a)

            while n:
                while i+n < len(a) and a[i+n] >= f and a[i+n] <= t:
                    i+=n
                n//=2
        else:
            n = len(a)-1
            i = n

            while n:
                while i-n >= 0 and a[i-n] < f and a[i-n] >= t:
                    i-=n
                n//=2

        return a[i] if a[i] == t else -1