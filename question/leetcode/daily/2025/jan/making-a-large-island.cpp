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

// DSU O(alpha(n)) find_set and union_sets
// O(alpha(n)) is approximately O(1) for a reasonable n
struct DSU {
    vl p; // parent
    vl s; // size
    ll g; // number of group

    // Constructor
    DSU(ll n) : p(n+1), s(n+1, 1), g(n) {
        rep(i, 0, n+1)
            p[i] = i;
    }

    // Find operation
    ll find(ll v) {
        if (v == p[v])
            return v;
        return p[v] = find(p[v]);
    }

    // Same set check
    bool same(ll u, ll v) {
        return find(u) == find(v);
    }

    // Union operation
    void join(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (s[u] < s[v])
                swap(u, v);
            p[v] = u;
            s[u] += s[v];
            g--;
        }
    }
};



class Solution {
public:
    int largestIsland(vector<vector<int>>& v) {
        int n = v.size();

        DSU dsu(n*n);
        int a = 0;

        rep(i,0,n){
            rep(j,0,n){
                if(v[i][j] == 1){
                    a = max(a,1);
                    for(auto [di,dj]: dirs){
                        int ni = i+di;
                        int nj = j+dj;

                        if(ni<0 or nj<0 or ni>=n or nj>=n or v[ni][nj] == 0) continue;
                        dsu.join(ni*n+nj, i*n+j);
                        a = max(a, (int)dsu.s[dsu.find(i*n+j)]);
                    }
                }
            }
        }

        rep(i,0,n){
            rep(j,0,n){
                if(v[i][j] == 0){
                    int s = 1;
                    unordered_set<int> used;
                    for(auto [di,dj]: dirs){
                        int ni = i+di;
                        int nj = j+dj;

                        if(ni<0 or nj<0 or ni>=n or nj>=n or v[ni][nj] == 0) continue;
                        int p = dsu.find(ni*n+nj);
                        if(not used.count(p)){
                            used.insert(dsu.find(ni*n+nj));
                            s+=dsu.s[dsu.find(ni*n+nj)];
                        }
                    }

                    a = max(a,s);
                }
            }
        }

        return a;
    }
};