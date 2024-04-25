#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> d;

        for (auto c: s)
            d[c]++;

        for (auto c: t){
            if (!d.count(c))
                return false;
            d[c]--;
            if (d[c] == 0){
                d.erase(c);
            }
        }

        return not (d.size());
    }
};