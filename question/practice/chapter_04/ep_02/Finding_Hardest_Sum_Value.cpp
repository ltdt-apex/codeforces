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

    ll n, m;cin >> n >> m;

    vvl v(n, vl(m));

    rep(i,0,n){
        rep(j,0,m){
            cin >> v[i][j];
        }
    }

    vvl a1(n, vl(m, LONG_LONG_MAX));
    rep(i,0,n){
        ll b = 0;
        rep(j,0,m){
            b = min(v[i][j], v[i][j]+b);
            a1[i][j] = min(a1[i][j],b);
        }
    }

    vvl a2(n, vl(m, LONG_LONG_MAX));
    rep(i,0,n){
        ll b = 0;
        repr(j,m-1,-1){
            b = min(v[i][j], v[i][j]+b);
            a2[i][j] = min(a2[i][j],b);
        }
    }

    vvl a3(n, vl(m, LONG_LONG_MAX));
    rep(j,0,m){
        ll b = 0;
        rep(i,0,n){
            b = min(v[i][j], v[i][j]+b);
            a3[i][j] = min(a3[i][j],b);
        }
    }

    vvl a4(n, vl(m, LONG_LONG_MAX));
    repr(j,m-1,-1){
        ll b = 0;
        repr(i,n-1,-1){
            b = min(v[i][j], v[i][j]+b);
            a4[i][j] = min(a4[i][j],b);
        }
    }

    // rep(i,0,n){
    //     rep(j,0,m){
    //         cout << a4[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = LONG_LONG_MAX;

    rep(i,0,n) rep(j,0,m) ans = min(ans, a1[i][j] + a2[i][j] + a3[i][j] + a4[i][j] - 3*v[i][j]);

    cout << ans << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;
    // cout << TC << endl;
    while (TC--) {
        solve(TC);
    }
}