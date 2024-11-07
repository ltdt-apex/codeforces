from typing import List, Optional

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        """
                    1
                2       3
            4       5
        6

        preorder = [1,2,4,6,5,3]
        inorder = [6,4,2,5,1,3]
        2
        left 4,6
        right 5

        empty return none
        create node from first preorder
        node.left = create left subtree
        node.right = create right subtree

        return node
        """
        if not preorder:
            return None

        cur = preorder[0]
        count_left = 0
        while inorder[count_left] != cur:
            count_left+=1
        
        node = TreeNode(
            cur,
            self.buildTree(preorder[1:1+count_left], inorder[:count_left]),
            self.buildTree(preorder[1+count_left:], inorder[count_left+1:])
        )

        return node
