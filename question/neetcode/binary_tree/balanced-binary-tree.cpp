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
        if(not node) return 0;

        int left = dfs(node->left, valid);
        int right = dfs(node->right, valid);

        if(abs(left-right)>1) valid = false;

        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        bool valid = true;
        dfs(root, valid);

        return valid;
    }
};