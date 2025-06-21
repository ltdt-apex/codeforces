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
#define range(i,b) for (int i = 0; i < b; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repr(i,a,b) for (int i = a; i > b; i--)
#define sq(a) (a)*(a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ceild(a,b) ((a)%(b) ? ((a)/(b) + 1) : (a)/(b))
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using ost = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll mod = 1e9 + 7;

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};


class Solution {
public:
    vector<int> kthSmallest(vector<int>& p, vector<int>& va, vector<vector<int>>& qs) {
        /*
        on9 question
        
        the only difficult part of this question is 
            only about how to merge subtree result

        and the solultion to it is abusing a data structure called ost
        
        */
        int n = p.size();

        vvi adj(n);

        rep(i,1,n){
            int v = i;
            int u = p[i];
            adj[u].pb(v);
        }

        int m = qs.size();

        vvii qsb(n);

        rep(i,0,m){
            int u = qs[i][0];
            int j = qs[i][1];

            qsb[u].pb({i,j});
        }

        vi a(m);
        vi vx(n);

        function<void(int,int)> dfs2 = [&](int u, int x){
            vx[u] = va[u]^x;
            for(auto v: adj[u]){
                dfs2(v,vx[u]);
            }
        };

        function<ost*(int)> dfs = [&](int u) -> ost*{
            ost* s = new ost();
            for(auto v: adj[u]){
                ost* ss = dfs(v);
                if(s->size()<ss->size()) swap(s,ss);
                for(auto x: *ss){
                    s->insert(x);
                }
            }

            s->insert(vx[u]);

            for(auto [i,j]: qsb[u]){
                if(j<=s->size()) a[i] = *s->find_by_order(j-1);
                else a[i] = -1;
            }

            return s;
        };

        dfs2(0,0);
        dfs(0);

        return a;
    }
};