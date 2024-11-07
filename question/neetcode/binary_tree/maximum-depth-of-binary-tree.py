from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    """
            1
        2       3
    4

    1: max(1+fun(2), 1+fun(3))
    2: max(1+fun(4), 1+fun(null))

    fun(null) return 0
    """

    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        return 1+max(self.maxDepth(root.left), self.maxDepth(root.right))