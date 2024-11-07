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
        unordered_map<char, int> count;

        for(int right=0; right<s.size(); right++){
            count[s[right]]++;
            while(count[s[right]] > 1){
                count[s[left]]--;
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};