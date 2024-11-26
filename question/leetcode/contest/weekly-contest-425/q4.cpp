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

    pll dfs(ll u, ll p, vvll& adj, int k){
        // return maximum weight sum of current and recursive node used such that
        // k-1 and k edges is used for current node to its recursive node edges(edges that connect to u except the one connect to parent p).
        vlll d;

        for(auto [v,w]: adj[u]){
            if(v==p) continue;

            auto [k1,k2] = dfs(v,u,adj,k);
            d.pb({k1+w-k2, k1+w, k2});
        }

        sort(rall(d));

        ll c1 = 0;
        ll c2 = 0;
        rep(i,0,d.size()){
            ll _,k1,k2;
            tie(_,k1,k2) = d[i];

            if(i<k-1) c1+=max(k1,k2);
            else c1+=k2;
            if(i<k) c2+=max(k1,k2);
            else c2+=k2;

        }

        return {c1,c2};
    }

    long long maximizeSumOfWeights(vector<vector<int>>& e, int k) {
        int n = e.size()+1;
        vvll adj(n);

        rep(i,0,n-1){
            int u = e[i][0];
            int v = e[i][1];
            int w = e[i][2];

            adj[u].pb({v,w});
            adj[v].pb({u,w});
        }

        return dfs(0,-1,adj,k).s;
    }
};
