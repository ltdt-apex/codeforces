from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        q = deque()
        ans = []

        if root:
            q.append(root)

        while q:
            ans.append(-1)
            for _ in range(len(q)):
                n = q.popleft()
                ans[-1] = n.val
                if n.left:
                    q.append(n.left)
                if n.right:
                    q.append(n.right)

        return ans


