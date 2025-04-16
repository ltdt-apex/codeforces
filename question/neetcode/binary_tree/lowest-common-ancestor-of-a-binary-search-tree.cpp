#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    pair<bool,bool> dfs(TreeNode* node, TreeNode* p, TreeNode* q, TreeNode*& ans){
        if(not node) return {false, false};

        auto [lp,lq] = dfs(node->left,p,q,ans);
        auto [rp,rq] = dfs(node->right,p,q,ans);

        bool found_p = lp or rp or p==node;
        bool found_q = lq or rq or q==node;

        if(found_p and found_q and ans==nullptr){
            ans = node;
        }

        return {found_p,found_q};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = nullptr;
        dfs(root,p,q,ans);

        return ans;
    }
};