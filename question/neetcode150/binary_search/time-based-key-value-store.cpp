#include <bits/stdc++.h>

using namespace std;

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> d;

    TimeMap() {
    }
    
    void set(string k, string v, int t) {
        d[k].push_back({t,v});
    }
    
    string get(string s, int t) {
        int n = d[s].size();

        int k = -1;
        for(int i=n;i;i/=2){
            while (k+i<n and d[s][k+i].first<=t){
                k+=i;
            }
        }

        if(k==-1) return "";
        return d[s][k].second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */