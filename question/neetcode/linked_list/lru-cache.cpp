#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    private:
        int c;
        unordered_map<int,int> cache;
        unordered_map<int,int> m;
        queue<int> q;
    public:
        LRUCache(int capacity) {
            c = capacity;
        }
        
        int get(int key) {
            if(m.count(key)){
                cache[key]++;
                q.push(key);
                return m[key];
            }
            return -1;
        }
        
        void put(int key, int value) {
            m[key] = value;
            cache[key]++;
            q.push(key);

            while(m.size()>c){
                int k = q.front(); q.pop();
                cache[k]--;
                if(cache[k]==0) m.erase(k);
            }
        }
    };
    
    /**
     * Your LRUCache object will be instantiated and called as such:
     * LRUCache* obj = new LRUCache(capacity);
     * int param_1 = obj->get(key);
     * obj->put(key,value);
     */