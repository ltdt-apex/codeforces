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

       int n = heights.size();
       int a = 0;
       stack<pair<int,int>> s; // (start, height) pair

       for(int i=0;i<n;i++){
            int h = heights[i];

            int start = i;
            while(not s.empty() and s.top().second>h){
                auto [pi,ph] = s.top(); s.pop();
                start = pi;

                a = max(a,ph*(i-pi));
            }

            s.push({start,h});
       }

       return a;
    }
};