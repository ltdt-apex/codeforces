from typing import List

class Solution:
    def containsDuplicate(self, a: List[int]) -> bool:
        s = set()
        for n in a:
            if n in s:
                return True
            s.add(n)
        return False