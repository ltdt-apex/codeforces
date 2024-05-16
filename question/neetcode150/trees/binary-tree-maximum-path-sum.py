from typing import Optional
import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxPathSum(self, node: Optional[TreeNode]) -> int:

        def dfs(node: Optional[TreeNode]):
            if not node:
                return -math.inf,-math.inf

            lefts, left = dfs(node.left)
            rights, right = dfs(node.right)

            ns = max(left+node.val, right+node.val, node.val)
            s = max(lefts,rights,left+node.val,right+node.val,left+right+node.val,node.val)

            return s,ns
        
        return dfs(node)[0]