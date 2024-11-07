# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def kthLargestPerfectSubtree(self, root: Optional[TreeNode], k: int) -> int:
        ans = []

        def dfs(node):
            if not node:
                return 0
            
            sl = dfs(node.left)
            sr = dfs(node.right)

            if(sl==-1 or sr==-1 or sl!=sr):
                return -1
            
            s = 1+sl+sr
            ans.append(s)

            return s
        
        dfs(root)
        ans.sort(reverse=True)
        # print(ans)
        if(len(ans)>=k):
            return ans[k-1]
        else:
            return -1
