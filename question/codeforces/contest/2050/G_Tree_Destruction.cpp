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

void dfs(int u, int p, vvi& adj, vl& deg, vl& dp, vl& dp2){
    priority_queue<int> q;
    for(auto v: adj[u]){
        if(p==v) continue;

        dfs(v,u,adj,deg,dp,dp2);
        q.push(dp[v]);
    }

    dp[u] = deg[u];
    if(q.size()>=1) dp[u] = max(dp[u], q.top() - 2 + deg[u]);

    if(q.size()>=2){
        ll f = q.top();
        q.pop();
        ll s = q.top();
        dp2[u] = f+s-4+deg[u]; 
    }
    else{
        dp2[u] = 0;
    }
}

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n;
    cin >> n;

    vvi adj(n+1);
    vl deg(n+1);

    rep(i,0,n-1){
        int u,v; cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    vl dp(n+1);
    vl dp2(n+1);

    dfs(1,-1,adj,deg,dp,dp2);

    ll a = 0;
    rep(i,1,n+1){
        // cout << dp[i] << " " << dp2[i] << endl;
        a=max(a,dp[i]);
        a=max(a,dp2[i]);
    }

    cout << a << endl;
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

