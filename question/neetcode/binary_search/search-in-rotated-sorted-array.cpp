#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (nums[0] > target and nums.back() < target) return -1;

        if(target < nums[0]){
            int j = n-1;
            int k = n-1;

            while(k){
                while(j-k>=0 and nums[j-k]>=target and nums[j-k] <= nums.back()) j-=k;
                k/=2;
            }
            
            if(nums[j]==target) return j;
            return -1;
        }
        else{
            int j = 0;
            int k = n;

            while(k){
                while(j+k<n and nums[j+k]<=target and nums[j+k]>=nums[0]) j+=k;
                k/=2;
            }

            if(nums[j]==target) return j;
            return -1;
        }

    }
};