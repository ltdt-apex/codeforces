#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(int i, int n, vector<int> nums, vector<int>& cur, vector<vector<int>>& ans){
            if(i==n){
                ans.push_back(cur);
                return;
            }

            cur.push_back(nums[i]);
            dfs(i+1,n,nums,cur,ans);
            cur.pop_back();
            dfs(i+1,n,nums,cur,ans);
        }

        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> cur;
            vector<vector<int>> ans;
            int n = nums.size();
            
            dfs(0,n,nums,cur,ans);

            return ans;
        }
    };