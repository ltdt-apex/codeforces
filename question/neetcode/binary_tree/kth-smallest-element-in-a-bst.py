from typing import Optional, Tuple

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        """
            3
        1       4
           2

        3 call fun(1,0) return 2, 3 is 3th
        1 call fun(none,0) return 0, 1 is 1st
        1 call fun(2,1)
            2 call fun(none, 1) return 0
            2 call fun(none, 1) return 0
            2 is 2nd (prefix + left)

        prefix
        node -> call fun(node.left, prefix) return num1, target1
        node -> call fun(node.right, prefix+num1+1) return num2, target2

        return num1+num2+1, target1 or target2 or current
        """

        def dfs(node: Optional[TreeNode], prefix: int, k: int) -> Tuple[int, int]:
            if not node:
                return 0, -1
            
            n_left, target_left = dfs(node.left, prefix, k)
            n_right, target_right = dfs(node.right, prefix+n_left+1, k)

            n = n_left + n_right + 1
            target = -1
            if target_left != -1:
                target = target_left
            elif target_right != -1:
                target = target_right
            elif prefix + n_left + 1 == k:
                target = node.val

            return n, target
        
        return dfs(root, 0, k)[1]
