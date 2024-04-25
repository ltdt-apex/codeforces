#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minWindow(string t, string s) {
        int l = 0;
        int al = 0, ar=INT_MAX;

        int n1 = s.size();
        int n2 = t.size();

        unordered_map<char, int> d1;
        for (auto c:s){
            d1[c]++;
        }

        unordered_map<char, int> d2;

        int have = 0, need = d1.size();
        
        for (int r=0; r<n2; r++){
            char c = t[r];
            d2[c]++;

            if(d1.count(c) and d2[c]==d1[c]){
                have++;
            }

            while (have==need){
                if (r-l < ar-al){
                    al = l, ar = r;
                }
                char c = t[l];
                d2[c]--;
                if(d1.count(c) and d2[c] < d1[c]){
                    have--;
                }
                l++;
            }

        }

        if (ar != INT_MAX) 
            return t.substr(al,ar-al+1);
        return "";
    }
};