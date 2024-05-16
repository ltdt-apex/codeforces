from typing import Optional
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:

        def dfs(node: Optional[TreeNode], m: int, h: int):
            if not node:
                return True
            
            if node.val <= m or node.val >= h:
                return False
            
            return dfs(node.left, m, node.val) and dfs(node.right, node.val, h)
        
        return dfs(root, -math.inf, math.inf)