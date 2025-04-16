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

    int dfs(TreeNode* node, int& a){
        if (not node) return 0;

        int left = dfs(node->left, a);
        int right = dfs(node->right, a);

        a = max(a,left+right);
        return 1+max(left,right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int a = 0;
        dfs(root,a);

        return a;
    }
};