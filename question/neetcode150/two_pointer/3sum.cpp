#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        vector<vector<int>> ans;
        int n = a.size();

        sort(a.begin(), a.end());

        for (int i =0; i < n;i++){
            if (a[i] > 0) break;

            if (i>0 and a[i] == a[i-1]) continue;

            int l = i+1, r = n-1;

            while(l<r){
                if(a[i]+a[l]+a[r] == 0){
                    ans.push_back({a[i],a[l],a[r]});
                    l++;
                    while (l < r and a[l] == a[l-1])
                        l++;
                }
                else if (a[i]+a[l]+a[r] < 0){
                    l++;
                }
                else
                    r--;
            }
        }

        return ans;
    }
};