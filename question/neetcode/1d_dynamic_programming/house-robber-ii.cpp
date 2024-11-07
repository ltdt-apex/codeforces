#include <bits/stdc++.h>
using namespace std;

/*

basically house robber i but two set of dp, first without first rob, second without last rob

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

        if (n==1) return nums[0];

        int ans = 0;
        vector<int> dp1(2);
        vector<int> dp2(2);

        for(int i = 0;i < n;i++){
            if(i!=0){
                int a = max(dp1[0], dp1[1]+nums[i]);
                int b = max(dp1[0], dp1[1]);

                dp1[0] = a;
                dp1[1] = b;
            }
            if(i!=n-1){
                int a = max(dp2[0], dp2[1]+nums[i]);
                int b = max(dp2[0], dp2[1]);

                dp2[0] = a;
                dp2[1] = b;
            }
        }

        return max(dp1[0], dp2[0]);

    }
};