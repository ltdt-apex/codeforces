#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        unordered_set<char> d;
        int ans = 0;

        for (int r=0; r < n;r++){
            char c = s[r];
            while (d.count(c)){
                d.erase(s[l]);
                l++;
            }
            d.insert(c);
            ans = max(ans, r-l+1);
        }

        return ans;
    }
};