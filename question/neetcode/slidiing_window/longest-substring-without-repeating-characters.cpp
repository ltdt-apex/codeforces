#include <bits/stdc++.h>

using namespace std;

/*  
s = "abcabcbb"

l,r
l = 0
r sweeping

m = count
left go forward until cur c count == 1

*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int left = 0;
        int n = s.size();

        unordered_map<char,int> m;

        for(int r=0;r<n;r++){
            m[s[r]]++;
            while(m[s[r]]>1){
                m[s[left]]--;
                left++;
            }

            ans = max(ans, r-left+1);
        }

        return ans;
    }
};