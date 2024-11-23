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
        while (i+1<nums.size() and nums[i] == nums[i+1]) i++;
        dfs(i+1, nums, ans, cur);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(0,nums,ans,cur);

        return ans;
    }
};