from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        stack = [root]

        while stack:
            n = stack.pop()

            if n:
                n.left, n.right = n.right, n.left
                stack.append(n.left)
                stack.append(n.right)

        return root