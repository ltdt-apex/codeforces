#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode*& node, vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir){
        if (il>ir) return;

        node = new TreeNode(preorder[pl]);

        for(int i=il;i<=ir;i++){
            if(inorder[i]==preorder[pl]){
                int s = i-il;

                // left
                int npl = pl+1;
                int npr = npl+s-1;
                int nil = il;
                int nir = i-1;
                dfs(node->left,preorder,inorder,npl,npr,nil,nir);

                // right
                npl = pl+1+s;
                npr = pr;
                nil = i+1;
                nir = ir;
                dfs(node->right,preorder,inorder,npl,npr,nil,nir);

                break;
            }
        }
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int n = preorder.size();

        dfs(root,preorder,inorder,0,n-1,0,n-1);

        return root;
    }
};