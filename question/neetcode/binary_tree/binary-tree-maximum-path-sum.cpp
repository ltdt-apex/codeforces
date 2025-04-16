#include<bits/stdc++.h>
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
        if(not node) return -3000;

        int left = dfs(node->left,a);
        int right = dfs(node->right,a);

        int cur = node->val + max({0,left,right});
        a = max({a, cur, left, right, node->val+left+right});

        return cur;
    }

    int maxPathSum(TreeNode* root) {
        int a = -INT_MAX;

        dfs(root,a);
        return a;
    }
};