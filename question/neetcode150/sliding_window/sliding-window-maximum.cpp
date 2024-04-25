#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<pair<int,int>> q;
        int n = a.size();

        vector<int> ans;

        for(int r=0;r<n;r++){
            int x = a[r];
            while(!q.empty() and q.front().first <= r-k){
                q.pop_front();
            }
            while(!q.empty() and q.back().second <= x){
                q.pop_back();
            }

            q.push_back({r,x});
            if (r+1>=k)
                ans.push_back(q.front().second);
        }

        return ans;
    }
};