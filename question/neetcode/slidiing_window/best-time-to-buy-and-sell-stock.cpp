#include <bits/stdc++.h>

using namespace std;

/*
[7,1,5,3,6,4]

low = 1
maxProfit = max(maxProfit, cur-low)
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int a = 0;

        for(int i=0;i<prices.size();i++){
            m = min(m,prices[i]);
            a = max(a, prices[i]-m);
        }

        return a;

    }
};