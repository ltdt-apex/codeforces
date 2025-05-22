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
#define range(i,b) for (int i = 0; i < b; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repr(i,a,b) for (int i = a; i > b; i--)
#define sq(a) (a)*(a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ceild(a,b) ((a)%(b) ? ((a)/(b) + 1) : (a)/(b))
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)

const ll mod = 1e9 + 7;

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

// https://cp-algorithms.com/graph/edmonds_karp.html
// Edmonds-Karp algorithm
// find max flow using bfs

// O(VE^2) in speed, 
    // O(E) for a single bfs, 
    // for each bfs, a edge e is saturated, 
        // it is only possible to reuse e when it has a longer distance to starting point
        // (not easy to prove that)
        // the number of times to reuse e is bounded longest possible path, which is O(V)
        // so it can only reuse O(V) times,
    // so all edges can reuse O(VE) times,
    // so in total, O(VE^2)
// O(V^2) in memory

struct MF {
    int n;
    vector<unordered_set<int>> adj;
    vvl cap;

    MF(vvii& adj) {
        n = adj.size();
        this->adj.assign(n, unordered_set<int>());
        this->cap.assign(n, vl(n));

        rep(u,0,n){
            for(auto [v,w]: adj[u]){
                this->adj[u].insert(v);
                this->adj[v].insert(u);
                this->cap[u][v] += w;
            }
        }
    }

    ll bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, ll>> q;
        q.push({s, LONG_LONG_MAX});
    
        while (!q.empty()) {
            int cur = q.front().first;
            ll flow = q.front().second;
            q.pop();
    
            for (auto next : adj[cur]) {
                if (parent[next] == -1 && cap[cur][next]) {
                    parent[next] = cur;
                    ll new_flow = min(flow, cap[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
    
        return 0;
    }
    
    ll maxflow(int s, int t) {
        ll flow = 0;
        vector<int> parent(n);
        ll new_flow;
    
        while (new_flow = bfs(s, t, parent)) {
            flow += new_flow;
            int cur = t;
            while (cur != s) {
                int prev = parent[cur];
                cap[prev][cur] -= new_flow;
                cap[cur][prev] += new_flow;
                cur = prev;
            }
        }
    
        return flow;
    }

    vii min_cut(int s){
        vi seen(n);
        queue<int> q;
        q.push(s);
        seen[s] = 1;

        while(not q.empty()){
            int u = q.front(); q.pop();
            for(auto v: adj[u]){
                if(not seen[v] and cap[u][v]>0){
                    seen[v] = 1;
                    q.push(v);
                }
            }
        }

        vii cut;
        for(int u=0;u<n;++u){
            if(seen[u]){
                for(auto v: adj[u]){
                    if(not seen[v] and cap[u][v]==0){
                        cut.pb({u,v});
                    }
                }
            }
        }

        return cut;
    }

    // find all distinct route 
    // work only for the graph with unweighted cap (i.e. cap = 1 for all edges)
    vvi find_path(int s, int t, vii& es){
        vvi tadj(n);
        for(auto [u,v]: es){
            if(cap[u][v]==0) tadj[u].pb(v);
        }

        vvi paths;

        while(not tadj[s].empty()){
            int u = s;
            vi path;
            path.pb(u);

            while(u!=t){
                int v = tadj[u].back();
                tadj[u].pop_back();
                path.pb(v);
                u=v;
            }

            paths.pb(path);
        }

        return paths;
    }
};


void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n,m;
    cin >> n >> m;

    vvii adj(n+1);

    rep(i,0,m){
        int u,v;
        cin >> u >> v;
        // cout << u << ' ' << v << endl;

        adj[u].pb({v,1});
        adj[v].pb({u,1});
    }

    MF mf(adj);

    mf.maxflow(1,n);
    vii mc = mf.min_cut(1);
    cout << mc.size() << endl;
    for (auto [u,v]: mc){
        cout << u << " " << v << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve(TC);
    }
}

