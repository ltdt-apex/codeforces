#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int n = products.size();
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string cur;

        for(auto c: searchWord){
            cur+=c;
            int k = lower_bound(products.begin(), products.end(), cur) - products.begin();
            vector<string> related;
            for(int i=0;i<3 and k+i<n;i++){
                // cout << "i: " << i << endl;
                string& s = products[k+i];
                if(cur.size()>s.size()) break;
                int match = 1;
                for(int j=0;j<cur.size();j++){
                    // cout << j << " " << match << endl;
                    if(s[j]!=cur[j]) match = 0;
                }
                if(not match) break;

                related.push_back(s);
            }

            ans.push_back(related);
        }

        return ans;
    }
};