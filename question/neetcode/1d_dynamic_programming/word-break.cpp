#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        abc

        i = 2
        j = 0...2

        j = 0, abc(0...2) and dp[0]
        j = 1, bc(1...2) and dp[1]
        c and dp[2]
        */
        unordered_set<string> set;
        for(auto w: wordDict){
            set.insert(w);
        }

        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                if(dp[j] and set.count(s.substr(j,i-j+1))) dp[i+1] = 1;
            }
        }

        return dp[n];
    }
};