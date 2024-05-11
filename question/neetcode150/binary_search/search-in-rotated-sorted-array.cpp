#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& a, int t) {
        int n = a.size();
        int f = a[0];
        
        if (t>=f){
            int k = 0;

            for(int i=n;i;i/=2){
                while(k+i < n and a[k+i]>f and a[k+i]<=t){
                    k+=i;
                }
            }

            if(a[k] == t) return k;
        }else{
            int k = n-1;

            for(int i=n;i;i/=2){
                while(k-i >= 0 and a[k-i]<f and a[k-i]>=t){
                    k-=i;
                }
            }
            if(a[k] == t) return k;
        }

        return -1;
    }
};