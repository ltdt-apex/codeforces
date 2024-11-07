#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        [0,1,0,2,3]
        maxleft = [0,0,1,1,2]
        maxright = [3,3,3,3,0]

        trap = [0,0,1,0,0]
        */

        int n = height.size();
        vector<int> maxleft(n);
        for(int i=0;i<n-1;i++){
            maxleft[i+1] = max(maxleft[i], height[i]);
        }
        vector<int> maxright(n);
        for(int i=n-1;i>0;i--){
            maxright[i-1] = max(maxright[i], height[i]);
        }

        int total = 0;
        for(int i=0;i<n;i++){
            total += max(0, min(maxleft[i], maxright[i])-height[i]);
        }

        return total;
    }
};