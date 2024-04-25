#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();

        int l = 0, r = n-1;
        int lm = a[l], rm = a[r];

        int ans = 0;

        while(l<r){
            if (lm < rm){
                l++;
                lm = max(lm, a[l]);
                ans += lm - a[l];
            }
            else{
                r--;
                rm = max(rm, a[r]);
                ans += rm - a[r];
            }
        }

        return ans;
    }
};