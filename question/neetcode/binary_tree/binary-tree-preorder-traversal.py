from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    # recursively
    # def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
    #     ans = []

    #     def dfs(node: Optional[TreeNode], ans: List[int]):
    #         if not node:
    #             return

    #         ans.append(node.val)
    #         dfs(node.left, ans)
    #         dfs(node.right, ans)

    #     dfs(root, ans)

    #     return ans

    # iteratively
    """
            1
        2       3
    4       5

    stack = [1]
    stack = [3,2]
    stack = [3,5,4]
    """

    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        stack = [root]
        ans = []

        while stack:
            node = stack.pop()

            if not node:
                continue

            ans.append(node.val)
            stack.append(node.right)
            stack.append(node.left)

        return ans
