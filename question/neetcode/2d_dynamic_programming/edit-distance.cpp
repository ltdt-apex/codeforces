#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1));

        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0) dp[i][j] = j;
                else if(j==0) dp[i][j] = i;
                else{
                    dp[i][j] = min({1+dp[i-1][j], 1+dp[i][j-1], dp[i-1][j-1] + 1 - (word1[i-1] == word2[j-1])});
                }
            }
        }

        return dp[n][m];
    }
};