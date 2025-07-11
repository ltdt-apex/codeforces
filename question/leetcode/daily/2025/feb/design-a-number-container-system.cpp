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

class NumberContainers {
private:
    unordered_map<int,int> m;
    unordered_map<int,priority_queue<int, vi, greater<int>>> l;
public:
    NumberContainers() {
        
    }
    
    void change(int i, int v) {
        m[i] = v;
        l[v].push(i);
    }
    
    int find(int v) {
        while(not l[v].empty() and m[l[v].top()]!=v) l[v].pop();

        if(l[v].empty()) return -1;
        else return l[v].top();
    }
};

// class NumberContainers {
// private:
//     unordered_map<int,int> m;
//     unordered_map<int,set<int>> l;
// public:
//     NumberContainers() {
        
//     }
    
//     void change(int i, int v) {
//         if(m.count(i)) l[m[i]].erase(i);

//         m[i] = v;
//         l[v].insert(i);
//     }
    
//     int find(int v) {
//         if(l[v].empty()) return -1;
//         return *l[v].begin();
//     }
// };

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */