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
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        vvll adj(n);

        ll m = e.size();
        rep(i,0,m){
            adj[e[i][0]].pb({e[i][1],e[i][2]});
            adj[e[i][1]].pb({e[i][0],e[i][2]});
        }

        vl d(n, LONG_LONG_MAX);
        set<pll> s;
        vvl p(n);
        d[0] = 0;
        s.insert({0,0});

        while(not s.empty()){
            ll u = s.begin()->s;
            s.erase(s.begin());


            for(auto [v,w]: adj[u]){
                if(d[u]+w==d[v]){
                    p[v].pb(u);
                }
                if(d[u]+w<d[v]){
                    p[v].clear();
                    p[v].pb(u);
                    s.erase({d[v],v});
                    d[v] = d[u]+w;
                    s.insert({d[v],v});
                }
            }
        }


        set<pll> ans;
        stack<ll> q;
        vl used(n);
        q.push(n-1);
        used[n-1] = 1;

        while(not q.empty()){
            ll u = q.top();
            q.pop();
            for(auto v: p[u]){
                ans.insert({u,v});
                if (!used[v]){
                    used[v] = 1;
                    q.push(v);
                }
            }
        }

        vector<bool> a(m);
        rep(i,0,m){
            if(ans.count({e[i][0], e[i][1]}) or ans.count({e[i][1], e[i][0]}))
                a[i] = true;
        }


        return a;
    }
};
