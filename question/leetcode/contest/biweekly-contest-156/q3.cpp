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
    int maxWeight(int n, vector<vector<int>>& es, int k, int t) {
        if(k==0) return 0;
        int m = es.size();
        vi in(n);

        vvi adj(n);
        vvii radj(n);

        rep(i,0,m){
            int u = es[i][0];
            int v = es[i][1];
            int w = es[i][2];

            adj[u].pb(v);
            radj[v].pb({u,w});
            in[v]++;
        }

        queue<int> q;

        rep(u,0,n){
            if(in[u]==0) q.push(u);
        }
        
        int dp[n][k+1][t];
        memset(dp, 0, sizeof(dp));
        int a = -1;

        while(not q.empty()){
            int u = q.front(); q.pop();
            dp[u][0][0] = 1;

            for(auto& v: adj[u]){
                in[v]--;
                if(in[v]==0) q.push(v);
            }

            int v = u;

            for(auto& [u,w]: radj[v]){
                rep(i,1,k+1){
                    rep(j,w,t){
                        dp[v][i][j] |= dp[u][i-1][j-w];
                        if(i==k and dp[v][i][j]) a = max(a,(int)j);
                    }
                }

            }
        }

        return a;
    }
};

