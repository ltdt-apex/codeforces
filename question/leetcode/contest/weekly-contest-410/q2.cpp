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
 
const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;
 
const int lt = 32;

int dfs(int& a, vvi& adj, int u, int p){
    vl t;
    for(auto v: adj[u]){
        if(v==p) continue;
        int x = 1 + dfs(a, adj, v, u);
        t.pb(x);
    }

    if(t.size()==0) a++;
    else{
        int x = t[0];
        bool ok = true;
        for(auto y: t){
            if(x!=y) ok = false;
        }
        if(ok) a++;
    }

    return 1 + accumulate(all(t), 0);
}

class Solution {
public:
    int countGoodNodes(vector<vector<int>>& v) {
        int n = v.size()+1;
        vvi adj(n);

        rep(i,0,n-1){
            adj[v[i][0]].pb(v[i][1]);
            adj[v[i][1]].pb(v[i][0]);
        }

        int a = 0;

        dfs(a,adj,0,-1);

        return a;
    }
};
