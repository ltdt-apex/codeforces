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

// DSU O(alpha(n)) find_set and union_sets
// O(alpha(n)) is approximately O(1) for a reasonable n
struct DSU {
    ll one; // is one index?
    vl p; // parent
    vl s; // size
    ll g; // number of group

    // Constructor
    DSU(ll n, ll o = 1) : one(1), p(n+1), s(n+1, 1), g(n) {
        rep(i, 0, n+1)
            p[i] = i;
    }

    // Find operation
    ll find(ll v) {
        if (v == p[v])
            return v;
        return p[v] = find(p[v]);
    }

    // Same set check
    bool same(ll u, ll v) {
        return find(u) == find(v);
    }

    // Union operation
    void join(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (s[u] < s[v])
                swap(u, v);
            p[v] = u;
            s[u] += s[v];
            g--;
        }
    }
};

 
void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n;
    cin >> n;

    vll p(n+1);
    rep(i,1,n+1){
        cin >> p[i].f >> p[i].s;
    }

    // for (auto [u,v]: p){
    //     cout << u << " " << v << endl;
    // }

    vlll adj;
    rep(i,1,n+1){
        ll w;
        cin >> w;
        adj.pb({w,i,0});
    }

    vl m(n+1);
    rep(i,1,n+1){
        cin >> m[i];
    }

    rep(i,1,n+1){
        rep(j,1,i){
            adj.pb({(m[i] + m[j])*(abs(p[i].f-p[j].f) + abs(p[i].s-p[j].s)),i,j});
        }
    }

    // for (auto [w,u,v]: adj){
    //     cout << w << " " << u << " " << v << endl;
    // }

    DSU dsu = DSU(n,1);
    sort(all(adj));

    ll ans=0;
    vl station;
    vll wire;

    for (auto [w,u,v]: adj){
        if (!dsu.same(u,v)){
            dsu.join(u,v);
            // cout << w << endl;
            ans += w;
            if(v==0){
                station.pb(u);
            }
            else{
                wire.pb({u,v});
            }
        }
    }

    cout << ans << endl;
    cout << station.size() << endl;
    for (auto x: station){
        cout << x << " ";
    }
    cout << endl;
    cout << wire.size() << endl;
    for (auto [u,v]: wire){
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