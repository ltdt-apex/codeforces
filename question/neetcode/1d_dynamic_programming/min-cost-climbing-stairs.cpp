#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int c1 = 0;
        int c2 = 0;

        for(auto c: cost){
            int nc = min(c1,c2) + c;
            c1 = c2;
            c2 = nc;
        }

        return min(c1,c2);
    }
};