from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSubtree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    
        def dfs(p: Optional[TreeNode], q: Optional[TreeNode]):
            if not p and not q:
                return True
            
            if p and q and p.val == q.val:
                return dfs(p.left, q.left) and dfs(p.right,q.right)
            else:
                return False
            
        if not p:
            return False

        if dfs(p,q):
            return True
        else:

            return self.isSubtree(p.left,q) or self.isSubtree(p.right,q)