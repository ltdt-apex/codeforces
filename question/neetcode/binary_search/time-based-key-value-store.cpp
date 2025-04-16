#include <bits/stdc++.h>
using namespace std;

class TimeMap {
    private:
        unordered_map<string, vector<pair<int,string>>> m;
    public:
        TimeMap() {
            
        }
        
        void set(string key, string value, int timestamp) {
            m[key].push_back({timestamp,value});
        }
        
        string get(string key, int timestamp) {
            vector<pair<int,string>>& v = m[key];

            int n = v.size();

            int k = n;
            int j = -1;

            while(k){
                while(j+k<n and v[j+k].first <= timestamp) j+=k;
                k/=2;
            }

            if(j==-1) return "";

            return v[j].second;
        }
    };
    
    /**
     * Your TimeMap object will be instantiated and called as such:
     * TimeMap* obj = new TimeMap();
     * obj->set(key,value,timestamp);
     * string param_2 = obj->get(key,timestamp);
     */