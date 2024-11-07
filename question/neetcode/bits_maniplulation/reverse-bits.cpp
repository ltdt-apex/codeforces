#include <bits/stdc++.h>

using namespace std;

/*
4 00...100
[0,0,1]
append 0 behind
[0,0,1,0,0,...]
rev
[0,0,0,...1,0,0]

convert back to int
*/


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int> bits;

        while(n){
            bits.push_back(n%2);
            n/=2;
        }

        int m = bits.size();
        for(int i=0;i<32-m;i++){
            bits.push_back(0);
        }

        reverse(bits.begin(), bits.end());

        int ans = 0;
        for(int i=0;i<32;i++){
            ans+=bits[i]<<i;
        }

        return ans;
    }
};