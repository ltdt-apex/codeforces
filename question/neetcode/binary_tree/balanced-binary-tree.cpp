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

    int dfs(TreeNode* node, bool& valid){
        int left = 0;
        int right = 0;

        if(node->left) left = dfs(node->left, valid);
        if(node->right) right = dfs(node->right, valid);
        
        if(abs(left-right)>1) valid = false;

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        bool valid = true;

        if(root) dfs(root,valid);

        return valid;
    }
};