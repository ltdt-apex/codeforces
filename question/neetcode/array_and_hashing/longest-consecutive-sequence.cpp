#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto x: nums){
            s.insert(x);
        }

        int ans=0;

        for(auto x: nums){
            if(s.count(x-1)) continue;
            int length = 0;
            while(s.count(x+length)){
                length++;
            }

            ans = max(ans, length);
        }

        return ans;
    }
};