#include <bits/stdc++.h>
using namespace std;

/*
nums = [1,2,3,1]


dp[0] = max of value if rob current house is an option
dp[1] = max of value if rob current house is not an option

dp[0] = max(dp[0], dp[1]+cur)
dp[1] = max(dp[0], dp[1])

reutrn max(dp[0], dp[1])

[0,0]
[0,1]
[1,2]
[2,4]
[4,4]
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(2);

        for(int i=0;i<n;i++){
            int nr = max(dp[0], dp[1]);
            int r = max(dp[1], dp[0] + nums[i]);

            dp = {nr, r};
        }

        return max(dp[0], dp[1]);
    }
};