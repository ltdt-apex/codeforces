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
        """
                1
            2       3
        4       5

        4, 5
        4+2+5
        4+2 5+2

        left+cur
        right+cur
        cur
        
        left+cur+right
        cur
        left
        right

        max of use cur +/without left/right
        max of anypath


        4,4
        5,5
        7,11
        3,3
        8,11
        """

        def dfs(node: Optional[TreeNode]):
            if not node:
                return -math.inf, -math.inf
            
            left_continue, left_max = dfs(node.left)
            right_continue, right_max = dfs(node.right)

            cur_continue = node.val + max(0, left_continue, right_continue)
            cur_max = max(cur_continue, left_max, right_max, node.val + left_continue + right_continue)

            return cur_continue, cur_max
        
        return dfs(root)[1]
    