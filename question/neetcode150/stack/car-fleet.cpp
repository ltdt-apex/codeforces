#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        int n = p.size();
        vector<pair<double, double>> ps;
        
        for(int i = 0;i < n;i++){
            ps.push_back({p[i],s[i]});
        }

        sort(ps.rbegin(), ps.rend());

        // for(auto [pos,speed]: ps){
        //     cout << pos << " " << speed << endl;
        // }

        int ans = 1;
        double ns = (t-ps[0].first)/ ps[0].second;
        for (auto [pos, speed]: ps){
            double time = (t-pos)/ speed;

            // cout << t << " " << pos << " " << speed << endl;
            // cout << time << endl;
            if (ns < time){
                ns = time;
                ans++;
            }
        }

        return ans;
    }
};