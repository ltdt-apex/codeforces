#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, int remaining, vector<int>& candidates, vector<int>& cur, vector<vector<int>>& ans){
        if(remaining==0){
            ans.push_back(cur);
            return;
        }

        if(remaining<0 or i>=candidates.size()){
            return;
        }

        cur.push_back(candidates[i]);
        dfs(i+1,remaining-candidates[i],candidates,cur,ans);
        cur.pop_back();
        while(i+1<candidates.size() and candidates[i] == candidates[i+1]) i++;
        dfs(i+1,remaining,candidates,cur,ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        vector<vector<int>> ans;

        dfs(0,target,candidates,cur,ans);

        return ans;
    }
};