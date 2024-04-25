#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& a) {
        int ans = 0;
        int m = a[0];
        for (auto n:a){
            m = min(n,m);
            ans = max(ans, n-m);
        }

        return ans;
    }
};