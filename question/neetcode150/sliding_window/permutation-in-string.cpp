#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> d;
        for (auto c: s1){
            d[c]++;
        }

        int n = s2.size();
        int n1 = s1.size();

        for (int r=0;r<n;r++){
            char c = s2[r];
            d[c]--;
            if(d[c]==0){
                d.erase(c);
            }

            if(r>=n1){
                char c = s2[r-n1];
                d[c]++;
                if (d[c]==0)
                    d.erase(c);
            }

            if (!d.size()){
                return true;
            }
        }

        return false;
    }
};