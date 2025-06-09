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

const ll mod = 1e9 + 7;

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    int goodSubtreeSum(vector<int>& v, vector<int>& p) {
        int n = v.size();
        vvi adj(n);

        rep(i,1,n){
            int u = i;
            int par = p[i];

            adj[par].pb(u);
        }

        vi bs(n);
        rep(i,0,n){
            int x = v[i];
            int b = 0;
            int ok = 1;

            while(x){
                int r = x%10;
                if((1<<r)&b) ok = 0;
                b|=(1<<r);
                x/=10;
            }

            if(not ok) bs[i]=-1;
            else bs[i] = b;
        }

        vvl dp(n, vl(1024));

        function<vi(int)> dfs = [&](int u) -> vi{
            vl cdp(1024);
            vi cs;

            for(auto v: adj[u]){
                vi c = dfs(v);
                for(auto n: c){
                    cs.pb(n);
                }
            }

            cs.pb(u);

            for(auto node: cs){
                int y = v[node];
                int b = bs[node];

                if(b!=-1){
                    vl ndp = cdp;
                    rep(i,0,1024){
                        if(i&b) continue;
                        cdp[i|b] = max(cdp[i|b], ndp[i] + y);
                        cdp[i|b]%=mod;
                    }
                }

                // cout << v[u] << " " << ok << endl;
            }

            dp[u] = move(cdp);

            return cs;
        };

        dfs(0);
        
        // rep(i,0,n){
        //     rep(j,0,10){
        //         cout << dp[i][j] << " ";
        //     }cout << endl;            
        // }cout << endl;
        
        ll a = 0;
        rep(i,0,n){
            ll m = 0;
            rep(j,0,1024){
                m = max(m,dp[i][j]);
            }

            // cout << m << endl;

            a+=m;
            a%=mod;
        }

        return a;
    }
};

