from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    # recursively
    # def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

    #     ans = []

    #     def dfs(node: Optional[TreeNode], ans: List[int]):
    #         if not node:
    #             return

    #         dfs(node.left, ans)
    #         dfs(node.right, ans)
    #         ans.append(node.val)

    #     dfs(root, ans)
    #     return ans
    
    # iteratively
    """
      1
     2 3
    4 5

    stack = [(1,unused)]
    stack = [(1,used),(3,unused),(2,unused)]
    stack = [(1,used),(3,unused),(2,used),(5,unused),(4,unused)]
    """
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = [(root,0)]
        ans = []

        while stack:
            node, used = stack.pop()

            if not node:
                continue

            if not used:
                stack.append((node, 1))
                stack.append((node.right, 0))
                stack.append((node.left, 0))

            else:
                ans.append(node.val)

        return ans