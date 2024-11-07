#include <bits/stdc++.h>

using namespace std;

/*
[0,1,2] (0+n)*(n+1)/2
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = n*(n+1)/2;

        for(auto num: nums){
            sum-=num;
        }

        return sum;
    }
};