#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp;

        for(auto x: nums){
            int i = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
            if(i!=dp.size()) dp[i] = x;
            else dp.push_back(x);
        }

        return dp.size();
    }
};