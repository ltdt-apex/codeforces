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
    void dfs(int u, int p, int d, int& md, int& f, vvi& adj){
        if(d>md){
            md = d;
            f = u;
        }
        for(auto v: adj[u]){
            if(v==p)continue;
            dfs(v,u,d+1,md,f,adj);
        }
    }

    int find(vvi& v){
        vvi adj(v.size()+1);

        for(auto x: v){
            int u = x[0];
            int v = x[1];

            adj[u].pb(v);
            adj[v].pb(u);
        }

        int md1 = -1;
        int f1 = -1;
        int md2 = -1;
        int f2 = -1;

        dfs(0,-1,0,md1,f1,adj);
        dfs(f1,-1,0,md2,f2,adj);

        return md2;
    }


    int minimumDiameterAfterMerge(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        // cout << find(v1) << ' ' << find(v2)  << endl;

        int d1 = find(v1);
        int d2 = find(v2);
        return max({d1,d2,ceild(d1,2)+ceild(d2,2)+1});
    }
};