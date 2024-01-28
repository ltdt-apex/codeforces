from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSameTree(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        q = deque()
        q.append((root1, root2))

        while q:
            n1, n2 = q.popleft()
            if not n1 and not n2:
                continue

            if n1 and not n2 or not n1 and n2 or n1.val != n2.val:
                return False
            
            q.append((n1.left, n2.left))
            q.append((n1.right, n2.right))
        
        return True
