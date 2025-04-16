#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<tuple<long long, int, int>> coords;

        for(auto p: points){
            coords.push_back({(long long)p[0]*p[0]+(long long)p[1]*p[1], p[0], p[1]});
        }

        sort(coords.begin(), coords.end());

        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            long long _;
            int x,y;
            tie(_,x,y) = coords[i];

            ans.push_back({x,y});
        }

        return ans;
    }
};