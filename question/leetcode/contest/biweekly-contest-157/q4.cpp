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

const int MAX_N = pow(10,5)+3;

// https://cp-algorithms.com/graph/lca_binary_lifting.html
// binary lifting
// find lowest common ancestor (lca) for any pair of nodes in O(log(n)) time
// O(nlog(n)) preprocessing
// O(log(n)) query
// O(nlog(n)) in memory

struct BL{
    int l;
    int timer;
    vector<int> tin, tout;
    vector<vector<int>> up;

    BL(int n, int root, vvi& adj): tin(n+1), tout(n+1), timer(0) {
        l = ceil(log2(n));
        up.assign(n+1, vector<int>(l+1));
        dfs(root, root, adj);
    }

    void dfs(int u, int p, vvi& adj){
        tin[u] = ++timer;

        up[u][0] = p;
        for(int i=1; i<=l; i++)
            up[u][i] = up[up[u][i-1]][i-1];

        for (auto v : adj[u]) {
            if (v==p) continue;
            dfs(v,u,adj);
        }

        tout[u] = ++timer;
    }

    bool is_ancestor(int u, int v)
    {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    }

    int lca(int u, int v)
    {
        if (is_ancestor(u, v))
        return u;
        if (is_ancestor(v, u))
        return v;
        for (int i = l; i >= 0; --i) {
            if (is_ancestor(up[u][i], v)) continue;
            u = up[u][i];
        }
        return up[u][0];
    }
};

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& es, vector<vector<int>>& qs) {
        int m = es.size();
        int n = m+1;
        int k = qs.size();
        vvi adj(n+1);

        rep(i,0,m){
            int u = es[i][0];
            int v = es[i][1];
            
            adj[u].pb(v);
            adj[v].pb(u);
        }

        BL bl(n+1,1,adj);

        vl dis(n+1);
        function<void(int,int,int)> dfs = [&](int u, int p, int d){
            dis[u] = d;
            for(auto v: adj[u]){
                if(v==p)continue;
                dfs(v,u,d+1);
            }
            // cout << ma << endl;
        };
        
        dfs(1,-1,0);

        vl dp(n);
        dp[0] = 0;
        dp[1] = 1;

        rep(i,2,n){
            dp[i] = 2*dp[i-1];
            dp[i]%=mod;
        }

        vi ans;
        rep(i,0,k){
            int u = qs[i][0];
            int v = qs[i][1];
            ll ma = dis[u]+dis[v]-2*dis[bl.lca(u,v)];

            ans.pb(dp[ma]);
        }

        return ans;
    }
};


