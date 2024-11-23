#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;

        deque<pair<int,int>> q;

        for(int r=0;r<n;r++){
            while(not q.empty() and q.back().first < nums[r]){
                q.pop_back();
            }
            q.push_back({nums[r], r});

            if(r>=k-1){
                ans.push_back(q.front().first);
                if(q.front().second == r-k+1) q.pop_front();
            }
        }

        return ans;
    }
};