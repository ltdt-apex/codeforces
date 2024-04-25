#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n = a.size();
        int l = 0, r = n-1;

        while (1){
            if(a[l]+a[r] == t){
                return {l+1, r+1};
            }
            else if (a[l]+a[r] < t){
                l++;
            }
            else
                r--;
        }
    }
};