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

    ll n1,n2,n3; cin >> n1 >> n2 >> n3;
    vl v1(n1);
    rep(i,0,n1) cin >> v1[i];
    sort(all(v1));

    vl v2(n2);
    rep(i,0,n2) cin >> v2[i];
    sort(all(v2));

    vl v3(n3);
    rep(i,0,n3) cin >> v3[i];
    sort(all(v3));

    ll n = n1+n2+n3;

    vl v(n);
    rep(i,0,n1) v[i] = v1[i];
    rep(i,n1,n1+n2) v[i] = v2[i-n1];
    rep(i,n1+n2,n) v[i] = v3[i-n2-n1];

    vl dp;
    for(auto x: v){
        ll i = lower_bound(all(dp), x) - dp.begin();

        if (i==dp.size()) dp.pb(x);
        else dp[i] = x;
    }

    cout << n - dp.size();
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