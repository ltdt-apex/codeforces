#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int c = 0;

        for(int i=0;i<n;i++){
            for(int j=0;i-j>=0 and i+j<n;j++){
                if(s[i-j]!=s[i+j]) break;
                c++;
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;i-j>=0 and i+1+j<n;j++){
                if(s[i-j]!=s[i+1+j]) break;
                c++;
            }
        }

        return c;
    }
};