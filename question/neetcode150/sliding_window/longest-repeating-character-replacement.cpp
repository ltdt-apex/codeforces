#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int n = s.size();
        int m = 0;
        int ans = 0;

        unordered_map<char, int> d;

        for (int r = 0;r < n;r++){
            char c = s[r];
            d[c]++;
            m = max(m, d[c]);

            if(r-l+1 > m+k){
                d[s[l]]--;
                l++;
            }

            ans = max(ans, r-l+1);
        }

        return ans;
    }
};