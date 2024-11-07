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

    void dfs(TreeNode* node, int cur, vector<vector<int>>& level){
        if(cur==level.size()){
            level.push_back({node->val});
        }else{
            level[cur].push_back(node->val);
        }

        if(node->left) dfs(node->left,cur+1,level);
        if(node->right) dfs(node->right,cur+1,level);


    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> level;

        if(root) dfs(root,0,level);

        vector<int> ans;

        for(auto l: level){
            ans.push_back(l.back());
        }

        return ans;
    }
};