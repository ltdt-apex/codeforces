#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        
        int k = n;
        int j = n;

        while(k){
            while(j-k>=0 and nums[j-k]<=nums.back()) j-=k;
            k/=2;
        }

        return nums[j];
    }
};
