#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);

        for(int i=1; i<n+1; i++){
            bits[i] = i%2 + bits[i/2];
        }

        return bits;
    }
};