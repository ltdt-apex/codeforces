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
        int maxProfit = 0;
        int low = INT_MAX;

        for(auto p: prices){
            low = min(low, p);
            maxProfit = max(maxProfit, p-low);
        }

        return maxProfit;
    }
};