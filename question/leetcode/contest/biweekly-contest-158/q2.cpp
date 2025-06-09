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


// class Solution {
// public:
//     long long maximumProfit(vector<int>& v, int k) {
//         int n = v.size();

//         vvl dp(k+1, vl(n+1));
//         ll a = 0;

//         rep(i,1,k+1){
//             ll ldp = dp[i-1][0];
//             ll dpn = -v[0]+dp[i-1][0];
//             ll dps = v[0]+dp[i-1][0];
//             rep(j,2,n+1){
//                 ll p = v[j-1];
//                 if(j>=i*2){
//                     dp[i][j] = max(dp[i][j], dpn+p);
//                     dp[i][j] = max(dp[i][j], -p+dps);
//                 }

//                 ldp = max(ldp, dp[i-1][j-1]);
//                 dpn = max(dpn, -p+ldp);
//                 dps = max(dps, p+ldp);
//                 a = max(a, dp[i][j]);
//             }

//         }

//         // rep(i,1,k+1){
//         //     rep(j,1,n+1){
//         //         cout << dp[i][j] << " ";
//         //     }cout << endl;
//         // }cout << endl;

//         return a;
//     }
// };

class Solution {
public:
    long long maximumProfit(vector<int>& v, int k) {
        int n = v.size();

        vvl dp(k+1, vl(n+1, 0));
        vvl buy(k+1, vl(n+1, -INT_MAX));
        vvl sell(k+1, vl(n+1, -INT_MAX));

        ll a = 0;
        rep(i,1,k+1){
            rep(j,1,n+1){
                dp[i][j] = max(dp[i][j], dp[i][j-1]);
                dp[i][j] = max(dp[i][j], buy[i][j-1]+v[j-1]);
                dp[i][j] = max(dp[i][j], sell[i][j-1]-v[j-1]);
                buy[i][j] = max(buy[i][j-1], dp[i-1][j-1]-v[j-1]);
                sell[i][j] = max(sell[i][j-1], dp[i-1][j-1]+v[j-1]);

                a = max(a,dp[i][j]);
            }
        }

        return a;
    }
};
