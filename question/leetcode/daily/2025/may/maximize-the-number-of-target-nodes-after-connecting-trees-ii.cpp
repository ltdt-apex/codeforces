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
    void dfs(vi& dis, vvi& adj, int u, int p, int d){
        dis[u] = d;

        for(auto v: adj[u]){
            if(v==p)continue;
            dfs(dis,adj,v,u,d+1);
        }
    };

    vector<int> maxTargetNodes(vector<vector<int>>& es1, vector<vector<int>>& es2) {
        function<vi(vvi&)> setup = [&](vvi& es) -> vi{
            int m = es.size();
            int n = m+1;

            vvi adj(n);

            rep(i,0,m){
                int u = es[i][0];
                int v = es[i][1];

                adj[u].pb(v);
                adj[v].pb(u);
            }

            vi dis(n);

            dfs(dis,adj,0,-1,0);

            return dis;
        };

        vi d1 = setup(es1);
        vi d2 = setup(es2);
        int n = d1.size();

        int c11 = 0;
        int c12 = 0;

        for(auto x: d1){
            if(x%2) c12++;
            else c11++;
        }

        int c21 = 0;
        int c22 = 0;

        for(auto x: d2){
            if(x%2) c22++;
            else c21++;
        }

        int a2 = max(c21,c22);

        vi a(n);

        rep(i,0,n){
            if(d1[i]%2) a[i] = c12+a2;
            else a[i] = c11+a2;
        }

        return a;
    }
};
