#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        stack<pair<int,int>> s;
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            while(!s.empty() and s.top().second<a[i]){
                auto [k,v] = s.top();
                s.pop();
                ans[k] = i-k;
            }
            s.push({i,a[i]});
        }

        return ans;
    }
};