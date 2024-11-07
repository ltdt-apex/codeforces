"""
        1
    2       3
4       5

ans = []

dfs(node, level)
dfs(root, 0)

ans = [[1], [2,3]]
1 -> call 2,3
"""


from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:

        ans = []

        def dfs(node: Optional[TreeNode], level: int, ans: List[List[int]]):
            if not node:
                return
            
            while len(ans) <= level:
                ans.append([])

            ans[level].append(node.val)
            dfs(node.left, 1+level, ans)
            dfs(node.right, 1+level, ans)

        dfs(root, 0, ans)

        return ans
