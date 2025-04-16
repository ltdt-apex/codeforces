#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    [1,2,3]

    dfs(0,nums)
        dfs(1,[1,2,3])
            dfs(2,[1,2,3])
            dfs(2,[1,3,2])
        dfs(1,[2,1,3])
        dfs(1,[3,2,1])

    if i == n
    push cur nums -> ans


    ans = [[]]

    if i==n
        push nums -> ans;

    dfs(0,nums)
        for(j=i;j<n;j++){
            swap(i,j);
            dfs(i+1);
            swap(i,j);
        }
    */
   void dfs(int i, int n, vector<int>& nums, vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(nums);
            return;
        }

        for(int j=i;j<n;j++){
            swap(nums[i], nums[j]);
            dfs(i+1,n,nums,ans);
            swap(nums[i], nums[j]);
        }
   }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();

        dfs(0,n,nums,ans);

        return ans;
    }
};