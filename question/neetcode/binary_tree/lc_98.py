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
        def valid(node, mi, ma):
            if not node:
                return True
            
            if mi<node.val<ma:
                return valid(node.left, mi, min(ma, node.val)) and valid(node.right, max(mi, node.val), ma)
            else:
                return False
            
        return valid(root,-math.inf, math.inf)
