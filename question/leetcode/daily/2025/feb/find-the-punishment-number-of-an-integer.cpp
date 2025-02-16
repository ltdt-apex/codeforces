#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for (int i = a; i < b; i++)

class Solution {
public:

    int f(int x, int target){
        if(target==0 and x==0) return 1;

        for(int m=10;m<=x*10;m*=10){
            if(f(x/m, target-x%m)) return 1;
        }

        return 0;
    }

    int punishmentNumber(int n) {
        int a = 0;
        rep(i,1,n+1){
            if(f(i*i, i)) a+=i*i;
        }

        return a;
    }
};