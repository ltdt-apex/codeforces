#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

typedef pair<int, int> pii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<tuple<int, int, int>> viii;

typedef tuple<int, int, int> tiii;

typedef long long ll;

typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;

typedef pair<ll, ll> pll;
typedef vector<pair<ll,ll>> vll;
typedef vector<vector<pair<ll,ll>>> vvll;
typedef vector<tuple<ll, ll, ll>> vlll;

typedef tuple<ll, ll, ll> tlll;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define range(i,b) for (ll i = 0; i < b; i++)
#define rep(i,a,b) for (ll i = a; i < b; i++)
#define repr(i,a,b) for (ll i = a; i > b; i--)
#define sq(a) (a)*(a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ceild(a,b) ((a)%(b) ? ((a)/(b) + 1) : (a)/(b))
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)

const ll mod = 1e9 + 7;

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

// class TaskManager {
// public:
//     set<pii, greater<pii>> s;
//     unordered_map<int,int> p;
//     unordered_map<int,int> u;
//     TaskManager(vector<vector<int>>& tasks) {
//         for(auto v: tasks){
//             int uid = v[0];
//             int tid = v[1];
//             int pr = v[2];

//             u[tid] = uid;
//             p[tid] = pr;
//             s.insert({pr,tid});
//         }
//     }
    
//     void add(int uid, int tid, int pr) {
//         u[tid] = uid;
//         s.insert({pr,tid});
//     }
    
//     void edit(int tid, int npr) {
//         s.erase({p[tid],tid});
//         p[tid] = npr;
//         s.insert({npr,tid});
//     }
    
//     void rmv(int tid) {
//         s.erase({p[tid],tid});
//     }
    
//     int execTop() {
//         if(s.size()==0) return -1;

//         auto [pr,tid] = *s.begin();
//         s.erase(s.begin());

//         return u[tid];
//     }
// };

class TaskManager {
public:
    int id;
    priority_queue<tiii> q;
    unordered_map<int, int> t2u;
    unordered_map<int, int> t2id;
    TaskManager(vector<vector<int>>& tasks) {
        id = 0;
        for(auto v: tasks){
            int uid = v[0];
            int tid = v[1];
            int pr = v[2];

            add(uid,tid,pr);
        }
    }
    
    void add(int uid, int tid, int pr) {
        t2u[tid] = uid;
        t2id[tid] = id;
        q.push({pr,tid,id});
        id++;
    }
    
    void edit(int tid, int npr) {
        t2id[tid] = id;
        q.push({npr,tid,t2id[tid]});
        id++;
    }
    
    void rmv(int tid) {
        t2id.erase(tid);
    }
    
    int execTop() {
        while(not q.empty()){
            int tid, pr, cid;
            tie(pr,tid,cid) = q.top(); q.pop();
            
            if(not t2id.count(tid) or t2id[tid]!=cid) continue;

            rmv(tid);
            return t2u[tid];
        }

        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */


