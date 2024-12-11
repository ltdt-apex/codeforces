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

    void dfs(int u, int p, vvi& adj, int d, int k, vi& a, int o){
        a[o]++;
        if(d==k) return;
        for(auto v: adj[u]){
            if(p==v) continue;

            dfs(v,u,adj,d+1,k,a,o);
        }
    }

    vector<int> maxTargetNodes(vector<vector<int>>& e1, vector<vector<int>>& e2, int k) {
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

        vi a1(n);
        vi a2(m);

        rep(i,0,n){
            dfs(i,-1,adj1,0,k,a1,i);
        }
        if(k!=0){
            rep(i,0,m){
                dfs(i,-1,adj2,0,k-1,a2,i);
            }
        }

        // rep(i,0,n){
        //     cout << a1[i] << endl;
        // }

        int t = *max_element(all(a2));

        rep(i,0,n){
            a1[i]+=t;
        }

        return a1;
    }
};


