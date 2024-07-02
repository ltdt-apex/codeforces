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

void dfs(vvl& adj, ll u, ll p, vl& d){
    for (auto v: adj[u]){
        if(p==v) continue;

        d[v] = d[u]+1;
        dfs(adj,v,u,d);
    }
}

ll fm(vl& d){
    ll m = 0;
    ll md = 0;

    rep(i,0,d.size()){
        if(d[i] > md){
            m = i;
            md = d[i];
        }
    }

    return m;
}


class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& v1, vector<vector<int>>& v2) {
        ll n = v1.size(), m = v2.size();

        vvl adj1(n+1);
        vvl adj2(m+1);

        rep(i,0,n){
            adj1[v1[i][0]].pb(v1[i][1]);
            adj1[v1[i][1]].pb(v1[i][0]);
        }
        rep(i,0,m){
            adj2[v2[i][0]].pb(v2[i][1]);
            adj2[v2[i][1]].pb(v2[i][0]);
        }

        vl d1(n+1);
        vl d2(m+1);
        ll v = -1;

        dfs(adj1,0,-1,d1);
        v = fm(d1);
        fill(all(d1),0);
        dfs(adj1,v,-1,d1);
        v = fm(d1);
        ll a1 = d1[v];

        dfs(adj2,0,-1,d2);
        v = fm(d2);
        fill(all(d2),0);
        dfs(adj2,v,-1,d2);
        v = fm(d2);
        ll a2 = d2[v];

        return max({a1,a2,ceild(a1,2)+ceild(a2,2)+1});
    }
};