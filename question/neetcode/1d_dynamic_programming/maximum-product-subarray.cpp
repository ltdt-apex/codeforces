#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int a = nums[0];

        int c = 1;
        for(int i=0;i<n;i++){
            c*=nums[i];
            a = max(a,c);

            if(c==0) c=1;
        }
        c=1;
        for(int i=n-1;i>=0;i--){
            c*=nums[i];
            a = max(a,c);

            if(c==0) c=1;
        }

        return a;
    }
};