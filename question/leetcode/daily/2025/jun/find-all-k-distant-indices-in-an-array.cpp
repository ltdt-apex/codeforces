#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<int> keys;

        for(int i=0;i<n;i++){
            if(nums[i]==key) keys.push_back(i);
        }

        vector<int> valid;
        int last = -1;

        for(auto start: keys){
            for(int i=max(last+1,start-k);i<=min(n-1,start+k);i++){
                valid.push_back(i);
                last = i;
            }
        }

        return valid;
    }
};