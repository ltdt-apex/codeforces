#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string clearDigits(string s) {
        int n = s.size();

        string a;

        for(auto c: s){
            if(c>='0' and c<='9') a.pop_back();
            else a+=c;
        }

        return a;
    }
};