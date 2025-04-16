#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        int n = nums.size();

        for(int i=0;i<n;i++){
            if(m.count(nums[i])) return {i,m[nums[i]]};
            
            m[target-nums[i]] = i;
        }

        return {-1,-1};
    }
};