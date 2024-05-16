

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, n: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        while n:
            if n.val > p.val and n.val > q.val:
                n = n.left
            elif n.val < p.val and n.val < q.val:
                n = n.right
            else:
                return n
            
        
