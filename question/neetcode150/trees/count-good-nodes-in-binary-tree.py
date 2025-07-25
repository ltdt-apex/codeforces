import math

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        ans = 0

        def dfs(node: TreeNode, h):
            nonlocal ans
            if not node:
                return
            
            if node.val >= h:
                ans += 1
            
            dfs(node.left, max(node.val, h))
            dfs(node.right, max(node.val, h))

        dfs(root,-math.inf)
        return ans