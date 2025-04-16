#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=1;i<=n;i++){
            if(i-1>=0 and s[i-1]!='0') dp[i]+=dp[i-1];
            if(i-2>=0 and (s[i-2]=='1' or (s[i-2]=='2' and s[i-1]<='6'))) dp[i]+=dp[i-2];
        }

        return dp[n];
    }
};