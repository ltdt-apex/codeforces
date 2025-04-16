#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i, int n, vector<int>& cur, vector<vector<int>>& ans, vector<int>& nums){
        if(i==n){
            ans.push_back(cur);
            return;
        }

        cur.push_back(nums[i]);
        dfs(i+1,n,cur,ans,nums);
        cur.pop_back();
        
        while(i+1<n and nums[i+1]==nums[i]) i++;
        dfs(i+1,n,cur,ans,nums);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        vector<int> cur;
        vector<vector<int>> ans;

        dfs(0,n,cur,ans,nums);

        return ans;
    }
};