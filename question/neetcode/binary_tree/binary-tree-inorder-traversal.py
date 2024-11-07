from typing import Optional, List

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    # recursively
    # def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:

    #     result = []

    #     def dfs(head: Optional[TreeNode], result):
    #         if not head:
    #             return
            
    #         dfs(head.left, result)
    #         result.append(head.val)
    #         dfs(head.right, result)

    #     dfs(root, result)

    #     return result

    # iteratively
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = [(root,0)]
        ans = []

        while stack:
            node, dir = stack.pop()

            if not node:
                continue

            if dir == 0:
                stack.append((node, 1))
                stack.append((node.left, 0))

            if dir == 1:
                ans.append(node.val)
                stack.append((node.right,0))

        return ans




