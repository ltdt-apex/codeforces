#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<tuple<long long,int,int>> dp;

        for(auto p: points){
            long long d = p[0]*p[0] + p[1]*p[1];
            dp.push_back({d,p[0],p[1]});
        }

        sort(dp.begin(), dp.end());

        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            int d,y,x;
            tie(d,y,x) = dp[i];
            ans.push_back({y,x});
        }

        return ans;
    }
};