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
    bool dfs(TreeNode* node, long long l, long long r){
        if(not node) return true;

        if(node->val<=l or node->val>=r) return false;

        return dfs(node->left,l,node->val) and dfs(node->right,node->val,r);
    }

    bool isValidBST(TreeNode* root) {
        return dfs(root, -LONG_LONG_MAX, LONG_LONG_MAX);
    }
};