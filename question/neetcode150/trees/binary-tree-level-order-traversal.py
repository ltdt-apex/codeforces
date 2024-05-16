from typing import Optional, List
from collections import deque

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        q = deque()
        ans = []

        if root:
            q.append((root, 0))

        while q:
            n,h = q.popleft()
            if not n:
                continue

            if len(ans) == h:
                ans.append([n.val])
            else:
                ans[h].append(n.val)
            
            q.append((n.left, h+1))
            q.append((n.right, h+1))

        return ans