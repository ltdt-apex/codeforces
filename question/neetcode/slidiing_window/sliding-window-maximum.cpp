#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int,int>> q;

        vector<int> ans;

        for(int right=0;right<n;right++){
            int x = nums[right];

            while(not q.empty() and q.back().second < x){
                q.pop_back();
            }

            q.push_back({right,x});

            if(right+1>=k){
                ans.push_back(q.front().second);
                if(right+1-k >= q.front().first) q.pop_front();
            }
        }

        return ans;
    }
};