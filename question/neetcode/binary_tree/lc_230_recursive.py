from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        a = []
        def move(node):
            if not node:
                return
            
            move(node.left)
            a.append(node.val)
            move(node.right)

        move(root)

        return a[k-1]