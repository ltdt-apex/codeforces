#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<pair<int,int>> dp(n+2);
        dp[0] = {-INT_MAX, 0};
        dp[1] = {-INT_MAX, 0};

        for(int i=0;i<n;i++){
            dp[i+2].first = max(dp[i+1].first, dp[i].second - prices[i]);
            dp[i+2].second = max(dp[i+1].second, dp[i+1].first + prices[i]);
        }

        return dp.back().second;
    }
};