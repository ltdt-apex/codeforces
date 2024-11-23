#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool caneat(vector<int>& piles, int h, int k){
        long long required = 0;

        for(auto p: piles){
            required += p/k + (p%k>0);
        }

        return required <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int j = *max_element(piles.begin(), piles.end());
        int k = j;

        while(j){
            while(k-j>=1 and caneat(piles,h,k-j)){
                k-=j;
            }
            j/=2;
        }

        return k;
    }
};