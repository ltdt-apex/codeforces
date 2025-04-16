#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        void dfs(int i, int s, int n, vector<int>& cur, vector<vector<int>>& ans, vector<int>& candidates, int target){
            if(s==target){
                ans.push_back(cur);
                return;
            }
            
            if(i==n or s>target){
                return;
            }

            cur.push_back(candidates[i]);
            dfs(i,s+candidates[i],n,cur,ans,candidates,target);
            cur.pop_back();
            dfs(i+1,s,n,cur,ans,candidates,target);
        }

        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<int> cur;
            vector<vector<int>> ans;
            int n = candidates.size();

            dfs(0,0,n,cur,ans,candidates,target);

            return ans;
        }
    };