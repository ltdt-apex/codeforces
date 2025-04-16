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
    void dfs(TreeNode* node, int d, vector<int>& a){
        if(not node) return;
        
        if(a.size()==d) a.push_back(node->val);
        else a[d] = node->val;

        dfs(node->left,d+1,a);
        dfs(node->right,d+1,a);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> a;

        dfs(root,0,a);

        return a;
    }
};