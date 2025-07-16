#include <bits/stdc++.h>
using namespace std;

// o + o = e
// o + e = o
// e + e = e

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int countOdds = 0;
        int countEvens = 0;
        int countAlts = 0;
        int curParity = 1-nums[0]%2;

        for(int i=0;i<n;i++){
            if(nums[i]%2==0) countOdds++;
            if(nums[i]%2==1) countEvens++;

            if(nums[i]%2!=curParity) {
                countAlts++;
                curParity=nums[i]%2;
            }
        }

        return max({countOdds, countEvens, countAlts});
    }
};