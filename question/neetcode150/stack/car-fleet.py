from typing import List

class Solution:
    def carFleet(self, t: int, ps: List[int], ss: List[int]) -> int:
        stack = []

        a = list(zip(ps,ss))
        a.sort(reverse=True)

        for p,s in a:
            # if stack:
            #     print((t-p)/s,(t-stack[-1][0])/stack[-1][1])
            if not stack or (t-p)/s > (t-stack[-1][0])/stack[-1][1]:
                stack.append((p,s))

        return len(stack)