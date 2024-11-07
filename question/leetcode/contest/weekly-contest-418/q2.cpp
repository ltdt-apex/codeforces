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

class Solution {
public:

    void dfs(set<int>& seen, int u, vvi& adj){
        seen.insert(u);

        for(auto v: adj[u]){
            if(seen.count(v))continue;
            else dfs(seen, v, adj);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& g) {
        vvi adj(n+1);

        ll m = g.size();

        rep(i,0,m){
            int u,v;
            u = g[i][0];
            v = g[i][1];
            adj[u].pb(v);
        }

        set<int> s1;
        dfs(s1, k, adj);

        set<int> s2;
        rep(i,0,n){
            if(s1.count(i))continue;
            for(auto v: adj[i]){
                s2.insert(v);
            }
        }

        bool ok = false;
        rep(i,0,n){
            if(s1.count(i) and s2.count(i)) ok = true;
        }

        vi ans;
        rep(i,0,n){
            if(s1.count(i) and not ok) continue;
            ans.pb(i);
        }

        return ans;
    }
};
