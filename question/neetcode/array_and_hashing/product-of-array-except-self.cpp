#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /*
        [1,2,3,4]

        pre = [1,1,2,6]
        suf = [24,12,4,1]
        */
        int n = nums.size();

        vector<int> prefix(n,1);
        vector<int> suffix(n,1);

        int pre = 1;
        for(int i=0;i<n-1;i++){
            pre*=nums[i];
            prefix[i+1] = pre;
        }
        int suf = 1;
        for(int i=0;i<n-1;i++){
            suf*=nums[n-i-1];
            suffix[n-i-2] = suf;
        }

        for(int i=0;i<n;i++){
            prefix[i]*=suffix[i];
        }

        return prefix;
    }
};