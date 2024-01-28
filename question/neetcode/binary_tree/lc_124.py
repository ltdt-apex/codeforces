from typing import Optional
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        def move(node):
            if not node:
                return -math.inf, -math.inf
            nl1, nl2 = move(node.left)
            nr1, nr2 = move(node.right)

            return max(node.val+nl1, node.val+nr1, node.val), max(nl2, nr2, node.val, node.val+nl1, node.val+nr1, node.val+nl1+nr1)
        
        n1, n2 = move(root)
        return n2
        

