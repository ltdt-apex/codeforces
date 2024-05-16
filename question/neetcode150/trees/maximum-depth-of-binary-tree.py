from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        stack = [(root,1)]
        ans = 0
        while stack:
            n,height = stack.pop()

            if n:
                ans = max(ans, height)
                stack.append((n.left,height+1))
                stack.append((n.right,height+1))

        return ans