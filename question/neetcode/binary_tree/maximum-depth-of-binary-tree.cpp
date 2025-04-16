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
    void dfs(TreeNode* node, int c, int& h){
        if(not node) return;

        h = max(c,h);
        dfs(node->left, c+1, h);
        dfs(node->right, c+1, h);
    }

    int maxDepth(TreeNode* root) {
        int m = 0;
        dfs(root, 1, m);

        return m;
    }
};