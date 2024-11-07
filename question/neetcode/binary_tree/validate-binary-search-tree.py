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
        """
                3
            2       4
        1               5

        min=-inf max=inf
        if not min<node<max return false
        else dfs(left) and dfs(right)
        2 < 3
        """

        def dfs(node: Optional[TreeNode], min_: int, max_: int):
            if not node:
                return True
            
            if not (min_<node.val<max_):
                return False
            
            return dfs(node.left,min_,node.val) and dfs(node.right,node.val,max_)
        
        return dfs(root,-math.inf,math.inf)