#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int>& cur){
        if(i==nums.size()){
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1, nums, ans, cur);
        cur.pop_back();
        dfs(i+1, nums, ans, cur);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(0,nums,ans,cur);

        return ans;
    }
};