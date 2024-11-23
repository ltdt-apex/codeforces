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
    void dfs(TreeNode* node, int max_, int& count){
        if(node->val >= max_) count++;

        max_ = max(max_, node->val);

        if(node->left) dfs(node->left, max_, count);
        if(node->right) dfs(node->right, max_, count);
    }

    int goodNodes(TreeNode* root) {
        int count = 0;

        if(root) dfs(root, -INT_MAX, count);

        return count;
    }
};