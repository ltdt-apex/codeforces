#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:

    string encode(vector<string>& ss) {
        string a;

        for(auto s: ss){
            a += to_string(s.size()) + '#' + s;
        }

        return a;
    }

    vector<string> decode(string s) {
        vector<string> a;

        int i = 0;
        while(i<s.size()){
            int j = 0;
            while (s[i+j]!='#'){
                j++;
            }

            int n = stoi(s.substr(i,j));
            a.push_back(s.substr(i+j+1, n));
            i+=j+1+n;
        }

        return a;
    }
};
