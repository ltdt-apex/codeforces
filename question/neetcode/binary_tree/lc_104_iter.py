from typing import Optional
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        q = deque()
        q.append((root,1))
        ans = 0

        while q:
            node, v = q.popleft()
            if not node:
                continue

            ans = max(ans, v)
            q.append((node.left, v+1))
            q.append((node.right, v+1))

        return ans
