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

    int dfs(int u, vvi& adj, vi& c, int cur, vi& g){
        c[u] = cur;
        g.pb(u);
        int a = 1;

        for(auto v: adj[u]){
            if(c[v]!=-1){
                if(c[v]==cur) return false;
            }
            else{
                a &= dfs(v,adj,c,1-cur,g);
            }
        }

        return a;
    }

    int magnificentSets(int n, vector<vector<int>>& e) {
        int m = e.size();

        vvi adj(n+1);
        vi c(n+1, -1);
        vvi gs;

        for(auto x: e){
            int u = x[0];
            int v = x[1];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        rep(i,1,n+1){
            if(c[i]==-1) {
                vi g;
                if(not dfs(i,adj,c,0,g)){
                    return -1;
                }
                gs.pb(g);
            }
        }

        int a = 0;

        for(auto g: gs){
            int m = 1;
            for(auto u: g){
                // cout << u << " ";
                queue<pii> s;
                vi seen(n+1);
                s.push({u,1});
                seen[u]=1;

                while(not s.empty()){
                    auto [u,d] = s.front();
                    s.pop();

                    for(auto v: adj[u]){
                        if(seen[v])continue;
                        seen[v]=1;
                        s.push({v,d+1});
                        m = max(m,d+1);
                    }
                }
            }
            // cout << endl;
            // cout << m << endl;

            a += m;
            // cout << a << endl;
        }

        return a;
    }
};