from typing import Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        q = []
        q.append((root, -1))

        while q:
            node,v = q.pop()

            if not node:
                continue

            if v == -1:
                q.append((node,1))
                q.append((node.left,-1))

            else:
                k-=1
                if k == 0:
                    return node.val
                q.append((node.right,-1))