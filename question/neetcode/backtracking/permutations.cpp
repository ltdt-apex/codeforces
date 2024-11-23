#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i, vector<int>& nums, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<nums.size();j++){
            swap(nums[i], nums[j]);
            dfs(i+1,nums,ans);
            swap(nums[j], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;

        dfs(0,nums,ans);
        
        return ans;
    }
};