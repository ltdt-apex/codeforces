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

struct MF {
    int n;
    vvi adj;
    vvi cap;

    MF(vvii& adj){
        n = adj.size();
        this->adj.assign(n, vi(n));
        this->cap.assign(n, vi(n));

        rep(u,0,n){
            for(auto [v,w]: adj[u]){
                this->adj[u].pb(v);
                this->adj[v].pb(u);
                cap[u][v] = w;
                cap[v][u] = 0;
            }
        }
    }

    int bfs(int s, int t, vector<int>& parent) {
        fill(parent.begin(), parent.end(), -1);
        parent[s] = -2;
        queue<pair<int, int>> q;
        q.push({s, INT_MAX});
    
        while (!q.empty()) {
            int cur = q.front().first;
            int flow = q.front().second;
            q.pop();
    
            for (auto next : adj[cur]) {
                if (parent[next] == -1 && cap[cur][next]) {
                    parent[next] = cur;
                    int new_flow = min(flow, cap[cur][next]);
                    if (next == t)
                        return new_flow;
                    q.push({next, new_flow});
                }
            }
        }
    
        return 0;
    }
    
    int maxflow(int s, int t) {
        int flow = 0;
        vector<int> parent(n);
        int new_flow;
    
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
};

unordered_map<int,int> fp(int x){
    unordered_map<int,int> c;

    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            c[i]++;
            x/=i;
        }
    }

    if(x>=2){
        c[x]++;
    }

    return c;
}


void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n,m;
    cin >> n >> m;

    vi v(n);
    vii es(m);

    rep(i,0,n){
        cin >> v[i];
    }

    rep(i,0,m){
        cin >> es[i].f >> es[i].s;
        es[i].f--;
        es[i].s--;
        if(es[i].f%2==1){
            swap(es[i].f, es[i].s);
        }
    }

    vector<unordered_map<int,int>> cs(n);
    unordered_set<int> primes;

    rep(i,0,n){
        cs[i] = fp(v[i]);

        for(auto [k,v]: cs[i]) primes.insert(k);
    }

    ll a = 0;

    for(auto p: primes){
        vvii adj(n+2);
        rep(i,0,m){
            adj[es[i].f].pb({es[i].s, INT_MAX});
        }
        rep(i,0,n){
            if(i%2==0) adj[n].pb({i,cs[i][p]});
            if(i%2==1) adj[i].pb({n+1,cs[i][p]});
        }
    
        MF mf(adj);
        a+=mf.maxflow(n,n+1);
    }

    cout << a << endl;
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

