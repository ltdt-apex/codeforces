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
    void dfs(TreeNode* node, int& s, int k, int& a){
        if(not node) return;

        dfs(node->left,s,k,a);
        s++;
        if(s==k) a=node->val;
        dfs(node->right,s,k,a);
    }

    int kthSmallest(TreeNode* root, int k) {
        int a = -1;
        int s = 0;

        dfs(root,s,k,a);

        return a;
    }
};