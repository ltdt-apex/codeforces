#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // "ab ab"
        vector<pair<string, string>> vl;
        vector<string> vd;
        
        for(auto log: logs){
            int n = log.size();
            for(int i=0;i<n;i++){
                if(log[i]== ' '){
                    if(log[i+1]>='0' and log[i+1]<='9'){
                        vd.push_back(log);
                    }
                    else{
                        vl.push_back({log.substr(i+1,n-i-1), log.substr(0,i+1)});
                    }
                    break;
                }
            }
        }

        sort(vl.begin(), vl.end());

        vector<string> ans;

        for(auto log: vl){
            ans.push_back(log.second + log.first);
        }
        for(auto log: vd){
            ans.push_back(log);
        }

        return ans;
    }
};