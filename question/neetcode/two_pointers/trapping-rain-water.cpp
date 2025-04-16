#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        /*
        3
        0 1 2 3 4
        0 1 2 3 4
        */
        int n = height.size();
        vector<int> left(n+2);
        vector<int> right(n+2);
        int a = 0;

        for(int i=1;i<=n;i++){
            left[i] = max(left[i-1], height[i-1]);
        }

        for(int i=n;i>=1;i--){
            right[i] = max(right[i+1], height[i-1]);
        }

        for(int i=1;i<=n;i++){
            // cout << left[i-1] << " " << right[i+1] << " " << max(0, min(left[i-1], right[i+1])-height[i-1]) << endl;
            a += max(0, min(left[i-1], right[i+1])-height[i-1]);
        }

        return a;
    }
};