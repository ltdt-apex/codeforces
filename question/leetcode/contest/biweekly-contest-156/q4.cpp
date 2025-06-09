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


class Solution {
    public:
        long long subtreeInversionSum(vector<vector<int>>& es, vector<int>& v, int k) {
            int n = v.size();
            int m = es.size();

            vvi adj(n);
            rep(i,0,m){
                int u = es[i][0];
                int v = es[i][1];

                adj[u].pb(v);
                adj[v].pb(u);
            }

            vvll dp(n, vll(k, {LONG_LONG_MAX, -LONG_LONG_MAX}));
            vll dp2(n, {LONG_LONG_MAX, -LONG_LONG_MAX});

            function<void(int,int)> dfs = [&](int u, int p){
                if(adj[u].size()==0){
                    // cout << "exit" << endl;
                    dp[u][0] = {v[u],v[u]};
                    dp[u][k-1] = {-abs(v[u]),abs(v[u])};
                    return;
                }
                
                for(auto v: adj[u]) {
                    if(v==p) continue;
                    dfs(v,u);
                }
                
                rep(i,0,k){
                    ll l = v[u];
                    ll r = v[u];
                    for(auto v: adj[u]){
                        if(v==p) continue;
                        if(dp[v][i].f != LONG_LONG_MAX) dp2[v].f = min(dp2[v].f, dp[v][i].f);
                        if(dp[v][i].s != -LONG_LONG_MAX) dp2[v].s = max(dp2[v].s, dp[v][i].s);
                        l+=dp2[v].f;
                        r+=dp2[v].s;
                    }
                    
                    if(i==0){
                        ll ma = max(abs(l), abs(r));
                        dp[u][k-1] = {-ma, ma};
                    }
                    else{
                        dp[u][i-1] = {l,r};
                    }
                }
                
                // cout << u << endl;
                // rep(i,0,k){
                //     cout << dp[u][i].f << " " << dp[u][i].s << endl;
                // }

            };

            dfs(0, -1);

            ll a = -1;
            rep(i,0,k){
                // cout << dp[0][i].s << endl;
                a = max(a, dp[0][i].s);
            }

            return a;
        }
    };
