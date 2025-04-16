#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int s = accumulate(nums.begin(), nums.end(), 0);

        if(s%2!=0) return false;
        int m = s/2;

        vector<int> dp(m+1);
        dp[0] = 1;

        for(auto x: nums){
            vector<int> ndp = dp;

            for(int i=1;i<=m;i++){
                if(i-x>=0 and dp[i-x]==1) ndp[i] = 1;
            }

            dp = move(ndp);
        }

        return dp[m];
    }
};