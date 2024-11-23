#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(int i, int count, int target, vector<int>& candidates, vector<vector<int>>& ans, vector<int>& cur){
        if(count==target){
            ans.push_back(cur);
            return;
        }
        if(i==candidates.size() or count > target) return;

        cur.push_back(candidates[i]);
        dfs(i, count+candidates[i], target, candidates, ans, cur);
        cur.pop_back();
        dfs(i+1, count, target, candidates, ans, cur);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> cur;

        dfs(0,0,target,candidates,ans,cur);

        return ans;
    }
};