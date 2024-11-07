#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int t = accumulate(nums.begin(), nums.end(), 0);

        if(t%2) return 0;

        t/=2;

        vector<int> dp(t+1);
        dp[0] = 1;

        for(int i=0;i<n;i++){
            vector<int> ndp(t+1);
            for(int j=0;j<t+1;j++){
                ndp[j] = dp[j];
                if(j-nums[i] >=0) ndp[j] |= dp[j-nums[i]];
            }

            dp = move(ndp);
        }

        return dp[t];
    }
};