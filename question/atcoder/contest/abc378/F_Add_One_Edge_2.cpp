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

void dfs(int u, vvi& adj, set<int>& seen, ll& count){

    // cout << u << " " << count << endl;
    seen.insert(u);

    for(auto v: adj[u]){
        if(adj[v].size() != 3){
            if(adj[v].size() == 2) count++;
            continue;
        }

        if(seen.count(v)) continue;

        dfs(v,adj,seen,count);
    }
}

ll C(ll n, ll k) {
    double res = 1;
    for (ll i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
    return (ll)(res + 0.01);
}

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n;
    cin >> n;
    vvi adj(n+1);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    ll a = 0;
    set<int> seen;

    rep(i,1,n+1){
        // cout << i << ": " << adj[i].size() << endl;
        if(adj[i].size()==3 and not seen.count(i)){
            // cout << "i: " << i << endl;
            ll count = 0;
            dfs(i,adj,seen,count);
            // cout << count << endl;

            a += C(count, 2);
        }
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

