from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        ans = []
        
        def dfs(cur: List, l, r):
            if not l and not r:
                ans.append("".join(cur))
                return
            if l:
                cur.append("(")
                dfs(cur, l-1, r)
                cur.pop()
            if r>l:
                cur.append(")")
                dfs(cur, l, r-1)
                cur.pop()

        dfs([], n, n)

        return ans