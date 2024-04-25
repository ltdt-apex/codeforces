#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& a) {
        int n = a.size();

        int l = 0, r = n-1;

        int ans = 0;

        while(l < r){
            ans = max(ans, min(a[l],a[r])*(r-l));

            if(a[l]<a[r])
                l++;
            else
                r--;
        }

        return ans;
    }
};