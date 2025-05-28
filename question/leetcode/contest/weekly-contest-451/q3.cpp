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
    int maxProfit(int n, vector<int>& v1, vector<int>& v2, vector<vector<int>>& es, int b) {
        vvi adj(n+1);
        rep(i,0,es.size()){
            int u = es[i][0];
            int v = es[i][1];

            adj[u].pb(v);
        }
        vvvl dp(n+1, vvl(2, vl(b+1)));

        function<void(int)> dfs = [&](int u){
            // vl dpn(b+1);
            vl dpn(b+1);
            vl dpb(b+1);
            
            for(auto v: adj[u]){
                dfs(v);
                repr(i,b,-1){
                    // dpn[i] = max(dpn[i], dp[v][0][i]);                        
                    rep(j,0,i+1){
                        // cout << "dpn: " << i << " " << j << " " << dpn[i-j] << " " << dp[v][1][j] << endl;
                        dpn[i] = max(dpn[i], dpn[i-j] + dp[v][0][j]);                      
                        dpb[i] = max(dpb[i], dpb[i-j] + dp[v][1][j]);
                        dpb[i] = max(dpb[i], dpb[i-j] + dp[v][0][j]);
                    }
                }
            }

            // rep(i,0,b){
            //     cout << i << " " << dpb[i] << endl;
            // }
            // if(v1[u-1]<=b) dpn[v1[u-1]] = v2[u-1]-v1[u-1];
            // if(v1[u-1]/2<=b) dpb[v1[u-1]/2] = v2[u-1]-v1[u-1]/2;

            rep(i,0,b+1){
                // dp[u][0][i] = max(dp[u][0][i], dpn[i]);
                dp[u][0][i] = max(dp[u][0][i], dpn[i]);
                if(i-v1[u-1]>=0) dp[u][0][i] = max(dp[u][0][i], dpb[i-v1[u-1]] + v2[u-1]-v1[u-1]);

                // dp[u][1][i] = max(dp[u][1][i], dpn[i]);
                // dp[u][1][i] = max(dp[u][1][i], dpn[i]);
                // dp[u][1][i] = max(dp[u][1][i], dpn[i]);
                if(i-v1[u-1]/2>=0) dp[u][1][i] = max(dp[u][1][i], dpb[i-v1[u-1]/2] + v2[u-1]-v1[u-1]/2);
            }
        };

        dfs(1);

        // rep(j,1,n+1){
        //     rep(k,0,2){
        //         rep(i,0,b+1){
        //             cout << j << ' ' << k << " " << i << " " << dp[j][k][i] << endl;
        //         }
        //     }
        // }

        return *max_element(all(dp[1][0]));
    }
};

