#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int ans = 0;
        int n = a.size();
        stack<pair<int,int>> s;

        for(int i = 0;i < n;i++){
            int h = a[i];
            int k = i;

            while(not s.empty() and s.top().second > h){
                auto [j,v] = s.top();
                s.pop();
                ans = max(ans, (i-j)*v);
                k = j;
            }

            s.push({k,h});
        }

        while(not s.empty()){
            auto [i,h] = s.top();
            s.pop();
            ans = max(ans, (n-i)*h);
        }

        return ans;
    }
};