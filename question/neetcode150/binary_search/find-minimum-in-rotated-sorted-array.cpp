#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int f = a[0];

        int k = 0;

        for(int i=n;i;i/=2){
            while(k+i < n and a[k+i]>f){
                k+=i;
            }
        }

        if(n==k+1){
            return f;
        }
        return a[k+1];
    }
};