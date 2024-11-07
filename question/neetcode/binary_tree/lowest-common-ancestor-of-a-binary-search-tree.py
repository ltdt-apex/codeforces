


from typing import Tuple

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        """
                1
            2       3
        4       5

        4,5

        1 -> lca(2)
        1 -> lca(3)

        2 -> lca(4)  
        2 -> lca(5)  

        4 -> lca(None) return false, false, -1
        4 -> lca(None) return false, false, -1
        left1 or left2 or cur.val = 4
        right1 or right2 or cur.val = 5
        val = -1

        5 -> lca(None)
        5 -> lca(None)
        """
        # this is for binary tree, the question ask for BST
        # def dfs(node: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> Tuple[bool, bool, 'TreeNode']:
        #     if not node:
        #         return False, False, None
            
        #     is_left_p, is_left_q, left_ancestor = dfs(node.left,p,q)
        #     is_right_p, is_right_q, right_ancestor = dfs(node.right,p,q)

        #     ancestor = None
        #     if left_ancestor:
        #         ancestor = left_ancestor
        #     if right_ancestor:
        #         ancestor = right_ancestor

        #     is_p = is_left_p or is_right_p or node is p
        #     is_q = is_left_q or is_right_q or node is q

        #     if is_p and is_q and not ancestor:
        #         ancestor = node

        #     return is_p, is_q, ancestor
        
        # return dfs(root, p, q)[2]


        """
                4
            2       5
        1       3

        1,3

        4 > 1,3
        call fun(2)

        if node.val > p and q
        call left
        else if node.val < p and q
        call right
        else return cur
        """

        if root.val < p.val and root.val < q.val:
            return self.lowestCommonAncestor(root.right,p,q)
        elif root.val > p.val and root.val > q.val:
            return self.lowestCommonAncestor(root.left,p,q)
        else:
            return root
