#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a1, vector<int>& a2) {
        int n1 = a1.size(), n2 = a2.size();

        if (n1 > n2){
            swap(a1,a2);
            swap(n1,n2);
        }

        int k = -1;
        int l = (n1+n2)/2;
        for(int i=l;i>0;i/=2){
            while(k+i<n1 and a1[k+i] <= a2[l-(k+i+1)]){
                k+=i;
            }
        }

        int a1l = k, a1r = k+1;
        int a2l = l-(k+1)-1, a2r = a2l+1;

        // cout << k << endl;
        // cout << a1l << endl;
        // cout << a1r << endl;
        // cout << a2l << endl;
        // cout << a2r << endl;

        if((n1+n2)%2){
            if(a1r==n1){
                return a2[a2r];
            }
            if(a2r==n2){
                return a1[a1r];
            }
            return min(a1[a1r], a2[a2r]);
        }else{
            int ma, mi;
            if(a1r==n1){
                ma = a2[a2r];
            }
            if(a2r==n2){
                ma = a1[a1r];
            }
            if(a1r!=n1 and a2r!=n2){
                ma = min(a1[a1r], a2[a2r]);
            }

            if(a1l==-1){
                mi = a2[a2l];
            }
            if(a2l==-1){
                mi = a1[a1l];
            }
            if(a1l!=-1 and a2l!=-1){
                mi = max(a1[a1l], a2[a2l]);
            }

            // cout << mi << " " << ma << endl;

            return (mi+ma)/2.0;
        }
    }
};