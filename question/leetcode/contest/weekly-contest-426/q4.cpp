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

class Solution {
public:

    void dfs(int u, int p, vvi& adj, vi& c, int cur){
        c[u] = cur;
        for(auto v: adj[u]){
            if(p==v) continue;

            dfs(v,u,adj,c,1-cur);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2) {
        int n = e1.size()+1;
        int m = e2.size()+1;

        vvi adj1(n);
        for(auto e: e1){
            int u = e[0];
            int v = e[1];

            adj1[u].pb(v);
            adj1[v].pb(u);
        }
        vvi adj2(m);
        for(auto e: e2){
            int u = e[0];
            int v = e[1];

            adj2[u].pb(v);
            adj2[v].pb(u);
        }

        vi c1(n);
        vi c2(m);

        dfs(0,-1,adj1,c1,0);
        dfs(0,-1,adj2,c2,0);

        // rep(i,0,n){
        //     cout << a1[i] << endl;
        // }

        int c11 = accumulate(all(c1),0);
        int c10 = n-c11;
        int c21 = accumulate(all(c2),0);
        int c20 = m-c21;

        int t;
        if(c21>0 and c20 > 0) t=max(c21, c20);
        else t = 0;
        
        vi ans(n);
        rep(i,0,n){
            if(c1[i]==1) ans[i] = t+c11;
            if(c1[i]==0) ans[i] = t+c10;
        }

        return ans;
    }
};