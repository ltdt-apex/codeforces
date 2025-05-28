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
    void dfs(vi& c, vvi& adj, int i, int u, int p, int k){
        c[i]++;
        if(k==0) return;

        for(auto v: adj[u]){
            if(v==p)continue;
            dfs(c,adj,i,v,u,k-1);
        }
    };

    vector<int> maxTargetNodes(vector<vector<int>>& es1, vector<vector<int>>& es2, int k) {
        function<vi(vvi&, int)> setup = [&](vvi& es, int k) -> vi{
            int m = es.size();
            int n = m+1;

            vvi adj(n);

            rep(i,0,m){
                int u = es[i][0];
                int v = es[i][1];

                adj[u].pb(v);
                adj[v].pb(u);
            }

            vi c(n);

            if(k<0) return c;
            rep(i,0,n) dfs(c,adj,i,i,-1,k);

            return c;
        };

        vi c1 = setup(es1,k);
        vi c2 = setup(es2,k-1);

        int n = c1.size();
        vi a(n);

        int m = *max_element(all(c2));

        rep(i,0,n){
            // cout << c1[i] << endl;
            a[i] = c1[i]+m;
        }

        return a;
    }
};
