#include <bits/stdc++.h>
 
using namespace std;
 
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

typedef pair<int, int> pii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<tuple<int, int, int>> viii;
 
typedef long long ll;

typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<vector<vector<ll>>> vvvl;

typedef pair<ll, ll> pll;
typedef vector<pair<ll,ll>> vll;
typedef vector<vector<pair<ll,ll>>> vvll;
typedef vector<tuple<ll, ll, ll>> vlll;
 
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
#define ceild(a,b) (a)%(b) ? ((a)/(b) + 1) : (a)/(b)
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
 
const ll mod = 1e9 + 7;
 
const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;
 
const int lt = 32;

bool isNumeric(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}
 
// dsu O(alpha(n)) find_set and union_sets
// O(alpha(n)) is approximately O(1) for a reasonable n
pair<vl,vl> init_set(ll n){
    vl parent(n);
    rep(i,0,n){
        parent[i] = i;
    }
    vl size(n, 1);
 
    return {parent, size};
}
 
void make_set(ll v, vl& parent, vl& size) {
    parent[v] = v;
    size[v] = 1;
}
 
ll find_set(ll v, vl& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}
 
ll same_set(ll u, ll v, vl& parent){
    return find_set(u, parent) == find_set(v, parent);
}
 
void union_sets(ll a, ll b, vl& parent, vl& size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}

void dfs(vl& vis, ll u, ll d, vvll& adj){
    if(vis[u]) return;
    vis[u] = 1;
    for(auto [v,w]: adj[u]){
        // cout << v << " " << w << " " << d << endl;

        if (d>=w and not vis[v]){
            // cout << v << " " << d-w << endl;
            dfs(vis,v,d-w,adj);
        }
    }
}
 
void solve(int TC) {
    ll n,m;
    cin >> n >> m;

    ll a,b;
    cin >> a >> b;

    vvll adj(n+1);
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    rep(i,1,n+1){
        sort(all(adj[i]));
    }

    vll tc(n+1);
    rep(i,1,n+1){
        ll t,c;
        cin >> t >> c;
        tc[i] = {t,c};
    }

    set<pll> s;
    s.insert({0,a});

    vl d(n+1, LONG_LONG_MAX);
    d[a] = 0;

    while(!s.empty()){
        ll u = s.begin()->s;
        s.erase({d[u],u});

        if (u==b){
            // rep(i,1,n+1){
            //     cout << d[i] << endl;
            // }
            cout << d[u] << endl;
            return;
        }

        ll rd = tc[u].f;
        // cout << rd << endl;
        ll c = tc[u].s;

        vl vis(n+1);

        dfs(vis,u,rd,adj);

        // cout << u << endl;
        // rep(v,1,n+1){
        //     if(vis[v]) cout << v << " ";
        // }
        // cout << endl;

        rep(v,1,n+1){
            if(v==u) continue;
            if(vis[v] and d[u]+c < d[v]){
                s.erase({d[v],v});
                d[v] = d[u]+c;
                s.insert({d[v],v});
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int TC = 1;
    // cin >> TC;
    while (TC--) solve(TC);
}