#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& a) {
        set<int> s;
        for (auto n: a){
            if (s.count(n)){
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};