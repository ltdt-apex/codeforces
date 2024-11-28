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

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& qs) {
        vvi adj(n);
        rep(i,0,n-1){
            adj[i].pb(i+1);
        }

        vi ans;

        for(auto q: qs){
            int u = q[0];
            int v = q[1];
            adj[u].pb(v);

            queue<pii> qq;
            vi seen(n);
            qq.push({0,0});
            seen[0] = 1;

            while(not qq.empty()){
                auto [u,d] = qq.front();
                qq.pop();

                if(u==n-1){
                    ans.pb(d);
                    break;
                }

                for(auto v: adj[u]){
                    if(seen[v]) continue;
                    seen[v] = 1;

                    qq.push({v,d+1});
                }
            }
        }

        return ans;
    }
};
