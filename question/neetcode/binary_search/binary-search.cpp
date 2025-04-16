#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int n = nums.size();

            int k = n;
            int j = -1;
            while(k){
                while(j+k<n and nums[j+k]<=target) j+=k;
                k/=2;
            }

            if(j==-1 or nums[j]!=target) return -1;

            return j;
        }
    };