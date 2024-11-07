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

    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& g) {
        int m = g.size();

        vvi adj(n);
        vi count(n);
        int r1 = -1;
        int r2 = -1;

        rep(i,0,m){
            int u,v;
            u = g[i][0];
            v = g[i][1];
            adj[u].pb(v);
            adj[v].pb(u);
            count[u]++;
            count[v]++;
        }

        rep(i,0,n){
            if(count[i]==1) r1 = i;
            if(count[i]==2) r2 = i;
        }

        int d1, d2;
        int s;
        vvi ans;
        vvi cm;

        if(r1!=-1) s = r1;
        else s = r2;

        ans.pb({s});

        ans[0][0] = s;
        set<int> used;
        used.insert(s);

        rep(t,1,n){
            int i = ans.size()-1;
            int j = ans.back().size();

            set<pair<int,int>> p1; 
            set<pair<int,int>> p2;
            set<pair<int,int>> pb;

            if(i>0) {
                int u = ans[i-1][j];
                for(auto v: adj[u]){
                    if(used.count(v)) continue;
                    p1.insert({adj[v].size(), v});
                }

            }
            if(j>0){
                int u = ans[i][j-1];
                for(auto v: adj[u]){
                    if(used.count(v)) continue;
                    p2.insert({adj[v].size(), v});
                }
            }

            for(auto v: p1){
                if(p2.count(v)) pb.insert(v);
            }

            if(i>0 and j==0) ans[i].pb((*p1.begin()).s);
            if(i==0 and j>0) ans[i].pb((*p2.begin()).s);
            if(i>0 and j>0) ans[i].pb((*pb.begin()).s);

            used.insert(ans[i][j]);
            if(r1!=-1) continue;

            if((j>0 and ((count[ans[i][j]]==2 and count[ans[i][j-1]]==2) or
                (count[ans[i][j]]==2 and count[ans[i][j-1]]==3)))
                or (i>0 and ans[i].size()==ans[i-1].size())) 
            ans.pb({});
        }

        if(r1==-1) ans.pop_back();

        return ans;
    }
};

