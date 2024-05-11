#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int k = 0;

        for(int i = n; i > 0;i/=2){
            while(k+i<n and a[k+i]<=t){
                k+=i;
            }
        }

        if(a[k]==t){
            return k;
        }
        return -1;
    }
};