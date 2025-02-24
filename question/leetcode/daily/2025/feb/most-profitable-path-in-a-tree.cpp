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
        void dfs(int u, int l, vvi& adj, vi& t, int ts, vi& p){
            t[u] = ts;
            p[u] = l;

            for(auto v: adj[u]){
                if(v==l) continue;
                dfs(v,u,adj,t,ts+1,p);
            }
        }

        void dfs2(int u, int l, vvi& adj, vi& v, int& a, int cur, vi& t, int ct){
            if(t[u]!=-1 and t[u]==ct) cur+=v[u]/2;
            else if(t[u]==-1 or t[u]>ct) cur+=v[u];

            for(auto j: adj[u]){
                if(j==l) continue;
                dfs2(j,u,adj,v,a,cur,t,ct+1);
            }
            
            if(adj[u].size()==1 and l!=-1) a = max(a, cur);
        }


        int mostProfitablePath(vector<vector<int>>& e, int b, vector<int>& v) {
            int n = e.size();

            vvi adj(n+1);
            rep(i,0,n){
                int u = e[i][0];
                int v = e[i][1];

                adj[u].pb(v);
                adj[v].pb(u);
            }

            vi t(n+1, -1);
            vi p(n+1, -1);
            dfs(b,-1,adj,t,0,p);

            vi bp(n+1);
            int s = 0;
            while(s!=b){
                bp[s] = 1;
                s = p[s];
            }
            bp[b] = 1;

            rep(i,0,n+1){
                if(not bp[i]) t[i] = -1;
            }

            int a = -INT_MAX;

            dfs2(0,-1,adj,v,a,0,t,0);

            return a;
        }
    };