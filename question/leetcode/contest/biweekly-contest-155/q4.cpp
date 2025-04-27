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


class Solution {
    public:
    int maxProfit(int n, vector<vector<int>>& es, vector<int>& ws) {
            /*
            bitmask dp,
            each state represent used nodes,
            e.g. s = 3(11) means node 0 and 1 is used.

            in each state, check which node can be the next to explore,
            then keep track of suboptimal answer using dp,
            
            so, in each state the time complexity is O(n),
            and there is 2^n state in total,
            so total time complexity is O(2^n * n), 
            very tight AC from time analysis, 
            but I guess the real complexity is much smaller.
            */
            cout << endl;        
            vvi adj(n);
            vi need(n);
            for(auto e: es){
                int u = e[0];
                int v = e[1];

                need[v] |= 1<<u;
                adj[u].pb(v);
            }

            vi dp(1<<n, -1);
            dp[(1<<n)-1] = 0;

            function<int(int, int)> dfs = [&](int s, int j){
                // cout << s << endl;
                if(dp[s]!=-1) return dp[s];

                int m = -1;

                rep(i,0,n){
                    int used = (s>>i) & 1;
                    int ok = (s & need[i]) == need[i];
                    if(ok and not used){
                        m = max(m, (int)j*ws[i] + dfs(s+(1<<i), j+1));
                    }
                }

                return dp[s] = m;
            };

            dfs(0,1);

            return dp[0];
        }
    };
