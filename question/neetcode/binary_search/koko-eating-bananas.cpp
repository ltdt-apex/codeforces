#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canEat(int x, vector<int>& piles, int h){
        long long c = 0;

        for(auto y: piles){
            c+=y/x;
            if(y%x)c++;
        }

        return c<=h;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int j = *max_element(piles.begin(), piles.end());
        int k = j;

        while(k){
            while(j-k>0 and canEat(j-k, piles, h)) j-=k;
            k/=2;
        }

        return j;
    }
};