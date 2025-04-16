#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    unordered_map<int, int> m;
    unordered_map<int, int> freq;
    queue<int> q;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            freq[key]++;
            q.push(key);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        m[key] = value;
        freq[key]++;
        q.push(key);

        while(m.size()>cap){
            int k = q.front(); q.pop();
            freq[k]--;
            if(freq[k]==0){
                m.erase(k);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */