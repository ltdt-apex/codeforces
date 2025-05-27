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


class Solution {
public:
    int largestPathValue(string v, vector<vector<int>>& es) {
        int n = v.size();
        int m = es.size();

        vvi adj(n);

        rep(i,0,m){
            int u = es[i][0];
            int v = es[i][1];

            adj[u].pb(v);
        }
        
        vi seen(n,0);
        vvi dis(n, vi(26,0));
        int c = 0;

        function<void(int)> dfs = [&](int u){
            if(seen[u]) return;
            seen[u] = 1;

            for(auto v: adj[u]){
                if(seen[v]==1){
                    c=1;
                    break;
                }
                else if(seen[v]==0){
                    dfs(v);
                }

                rep(i,0,26){
                    dis[u][i] = max(dis[u][i], dis[v][i]);
                }
            }

            seen[u]=2;
            dis[u][v[u]-'a']++;
        };

        rep(i,0,n){
            dfs(i);
        }

        if(c) return -1;

        int a = 0;
        rep(i,0,n){
            rep(j,0,26){
                a = max(a, dis[i][j]);
            }
        }

        return a;
    }
};