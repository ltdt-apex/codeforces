#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // [1]
    // 1,1,1,2

    void dfs(int i, int remaining, int n, vector<int>& cur, vector<vector<int>>& ans, vector<int>& candidates){
        if(remaining==0){
            ans.push_back(cur);
            return;
        }    

        if(i==n or remaining<0){
            return;
        }

        cur.push_back(candidates[i]);
        dfs(i+1,remaining-candidates[i],n,cur,ans,candidates);
        cur.pop_back();

        while(i+1<n and candidates[i+1] == candidates[i])i++;
        dfs(i+1,remaining,n,cur,ans,candidates);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;
        int n = candidates.size();

        dfs(0,target,n,cur,ans,candidates);

        return ans;
    }
};