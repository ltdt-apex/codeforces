#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*
        [2,5,6,7,3]

        5*3 = 15

        6,7
        6*2
                        h  l      r  (r-l)*h
        stack = [(5,0),(6,1)] (3,3)
        */

        heights.push_back(0);

        stack<pair<int,int>> s;
        int maxArea = 0;

        int n = heights.size();
        for(int i=0;i<n;i++){
            int h = heights[i];

            int start = i;
            while(not s.empty() and s.top().first > h){
                auto [h_old, i_old] = s.top();
                start = i_old;
                s.pop();
                int area = h_old*(i-i_old);
                maxArea = max(area, maxArea);
            }

            s.push({h,start});
        }

        return maxArea;
    }
};