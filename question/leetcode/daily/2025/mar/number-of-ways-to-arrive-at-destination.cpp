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
        int countPaths(int n, vector<vector<int>>& es) {
            vvii adj(n);
            for(auto e: es){
                int u = e[0];
                int v = e[1];
                int w = e[2];

                adj[u].pb({v,w});
                adj[v].pb({u,w});
            }
            

            priority_queue<pll, vll, greater<pll>> q;
            vl dp(n);
            vl dist(n, LONG_LONG_MAX);
            dist[0] = 0;
            dp[0] = 1;

            q.push({0,0});

            while(not q.empty()){
                auto [d,u] = q.top(); q.pop();

                if (dist[u]!=d) continue;
                
                for(auto [v,w]: adj[u]){
                    if(d+w < dist[v]){
                        dp[v] = dp[u];
                        dist[v] = d+w;
                        q.push({d+w,v});
                    }
                    else if(d+w <= dist[v]){
                        dp[v] += dp[u];
                        dp[v]%=mod;
                    }
                }
            }

            return dp[n-1];
        }
    };