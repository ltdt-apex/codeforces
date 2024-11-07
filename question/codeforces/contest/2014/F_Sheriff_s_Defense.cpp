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

ll dfs(vvl& dp, vvi& adj, ll u, ll used, ll c, ll p, vi& score){
    // cout << u << " " << used << endl;
    if(dp[u][used] != -LONG_LONG_MAX){
        // cout << "wtf" << endl;
        return dp[u][used];
    }

    ll a = 0;
    if(used){
        a+=score[u];
        for(auto v: adj[u]){
            if(v==p)continue;
            a+=max(dfs(dp,adj,v,0,c,u,score), dfs(dp,adj,v,1,c,u,score)-2*c);
        }
    }
    else{
        for(auto v: adj[u]){
            if(v==p)continue;
            a+=max(dfs(dp,adj,v,0,c,u,score), dfs(dp,adj,v,1,c,u,score));
        }
    }

    return dp[u][used] = a;
}


void solve(int TC) {
    ll n,c;
    cin >> n >> c;

    vi score(n+1);
    rep(i,1,n+1) cin >> score[i];

    vvi adj(n+1);
    rep(i,0,n-1){
        int u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }

    vvl dp(n+1, vl(2, -LONG_LONG_MAX));
    cout << max(dfs(dp,adj,1,0,c,-1,score), dfs(dp,adj,1,1,c,-1,score)) << endl;
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

