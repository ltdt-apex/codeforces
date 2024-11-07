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

const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;

const int lt = 32;

// https://cp-algorithms.com/data_structures/segment_tree.html
// segment tree
// O(n) build
// O(log n) query
// O(log n) update

// O(n) in memory
struct ST {
    ll n;
    vii t;

    ST(vii& a): n(a.size()), t(4*n) {
        build(a, 1, 0, n-1);
    }

    pii combine(pii a, pii b){
        // return a + b;
        // return max(a,b);
        // return min(a,b);


        if(a.f > b.f) return a;
        if(a.f < b.f) return b;

        if(a.s < b.s) return a;
        else return b;
    }

    void build(vii& a, int v, int tl, int tr){
        if(tl==tr) t[v] = a[tl];
        else {
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    pii query(int v, int tl, int tr, int l, int r){
        if(l>r) return {-INT_MAX,-1};
        // if(l>r) return LONG_LONG_MAX; // for min queries
        if (l==tl and r==tr) {
            return t[v];
        }

        int tm = (tl+tr)/2;
        return combine(query(v*2, tl, tm, l, min(r,tm)),
            query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    pii query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    void update(int v, int tl, int tr, int pos, pii new_v){
        if (tl==tr) {
            t[v] = new_v;
        }
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm) update(v*2, tl, tm, pos, new_v);
            else update(v*2+1, tm+1, tr, pos, new_v);

            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    void update(int pos, pii new_v){
        update(1, 0, n-1, pos, new_v);
    }

    void debug(int v, int tl, int tr){
        // cout << v << " " << tl << "-" << tr << " " << t[v] << endl;
        if (tl==tr) return;
        
        int tm = (tl+tr)/2;
        debug(v*2, tl, tm),
        debug(v*2+1, tm+1, tr);
    }

    void debug(){
        debug(1, 0, n-1);
    }
};



pll dfs(int u, vvl& adj, vector<set<pll>>& d, int last){
    pll m = {0,-1};
    d[u].insert({0,-1});
    for(auto v: adj[u]){
        if(v==last) continue;
        pll p = dfs(v, adj, d, u);
        d[u].insert({-p.f, p.s});
        if (m.f < p.f){
            m = p;
        }
    }

    return {m.f+1,u};
}

void dfs2(int u, vvl& adj, vector<set<pll>>& d, ST& st, vl& ans, int depth, vvll& qs, int last){
    for(auto [i,s]: qs[u]){
        ll d1 = -((*d[u].begin()).f);

        auto [inc, dep] = st.query(max(0,int(depth-s)), depth-1);

        if(inc == -INT_MAX) ans[i] = d1;
        else {
            ll d2 = inc+depth;
            ans[i] = max(d1,d2);
        }
        // cout << inc << " " << dep << endl;
        // cout << -int((*d[u].begin()).f) << endl;
        // cout << ans[i] << endl;
    }

    for(auto v: adj[u]){
        if(v==last) continue;
        for(auto [dd, vv]: d[u]){
            if(v!=vv) {
                st.update(depth, {-dd-depth, depth});
                break;
            }
        }
        dfs2(v,adj,d,st,ans,depth+1,qs,u);
    }
}


void solve(int TC) {
    // ll n;
    // cin >> n;
    int n; cin >> n;

    vvl adj(n+1);

    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvll qs(n+1);
    int m;
    cin >> m;

    rep(i,0,m){
        int u,s;
        cin >> u >> s;

        qs[u].pb({i,s});
    }

    vector<set<pll>> d(n+1);
    dfs(1,adj,d,-1);

    // rep(i,1,n+1){
    //     for(auto [dd,v]: d[i]){
    //         cout << i << " " << v << " " << dd << endl;
    //     }
    // }

    vii par(n+1, {-INT_MAX,-1});
    ST st(par);
    vl ans(m);

    dfs2(1,adj,d,st,ans,0,qs,-1);

    rep(i,0,m){
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve(TC);
    }
}
