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
 
void dfs(int u, int p, vvl&adj, vl& d){
    for(auto v: adj[u]){
        if(v!=p){
            if(v%2) d[v] = d[u] + 1;
            else d[v] = d[u] + 2;
            dfs(v,u,adj,d);
        }
    }
}

int f(vl& d){
    ll m = 0;
    ll a = 0;
    rep(i,0,d.size()){
        if(d[i]>m){
            m = d[i];
            a = i;
        }
    }

    return a;
}

class Solution {
public:
    vector<int> timeTaken(vector<vector<int>>& v) {
        int m = v.size();
        int n = m+1;

        vvl adj(n);

        rep(i,0,m){
            adj[v[i][0]].pb(v[i][1]);
            adj[v[i][1]].pb(v[i][0]);
        }

        vl d1(n);
        dfs(0,-1,adj,d1);
        ll m2=f(d1);

        vl d2(n);
        dfs(m2,-1,adj,d2);
        ll m3=f(d2);

        // rep(i,0,n){
        //     cout << d2[i] << ' ';
        // }cout << endl;

        // cout << m2 << endl;

        vl d3(n);
        dfs(m3,-1,adj,d3);

        // rep(i,0,n){
        //     cout << d3[i] << ' ';
        // }cout << endl;

        // cout << m3 << endl;

        vi a(n);
        rep(i,0,n){
            ll t1 = d2[i] + (2-m2%2) - (2-i%2);
            ll t2 = d3[i] + (2-m3%2) - (2-i%2);

            a[i] = max(t1,t2);
        }

        return a;
    }
};