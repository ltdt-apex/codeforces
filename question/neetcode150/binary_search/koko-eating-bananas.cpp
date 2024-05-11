#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool ok(vector<int>& a, int k, int h){
        int ans = 0;
        for(auto n:a){
            ans += n/k + (n%k!=0);
            if (ans > h){
                return false;
            }
        }
        return true;
    }

    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int k = *max_element(a.begin(), a.end());

        for (int i=k;i>0;i/=2){
            while(k-i>0 and ok(a,k-i,h)){
                k-=i;
            }
        }

        return k;
    }
};