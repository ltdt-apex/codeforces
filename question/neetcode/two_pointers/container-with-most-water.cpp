#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n-1;
        int a = 0;

        while(l<r){
            a = max(a, min(height[l], height[r])*(r-l));
            if(height[l]<height[r])l++;
            else r--;
        }

        return a;
    }
};