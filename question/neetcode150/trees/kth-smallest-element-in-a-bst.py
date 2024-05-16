from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        stack = []
        stack.append((root,0))

        while stack:
            n, v = stack.pop()
            if not n:
                continue
            if v == 0:
                stack.append((n,1))
                stack.append((n.left,0))
            else:
                k-=1
                if k==0:
                    return n.val
                stack.append((n.right,0))
