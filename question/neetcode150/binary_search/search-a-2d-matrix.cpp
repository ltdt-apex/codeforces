#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int t) {
        int n = a.size(), m = a[0].size();

        int k = 0;

        for(int i=n*m;i>0;i/=2){
            while((k+i)<n*m and a[(k+i)/m][(k+i)%m]<=t){
                k+=i;
            }
        }

        return a[k/m][k%m] == t;
    }
};