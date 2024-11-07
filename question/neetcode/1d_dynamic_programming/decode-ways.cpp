#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();

        int c1 = 0;
        int c2 = 1;

        for(int i=0;i<n;i++){
            int cn = 0;
            if(s[i]!='0') cn = c2;
            if(i!=0 and ((s[i-1]=='2' and s[i]<='6') or s[i-1]=='1')){
                // cout << "test" << (s[i-1]=='2' and s[i]<='6') << endl;
                cn += c1;
            }

            c1 = c2;
            c2 = cn;
        }

        return c2;
    }
};