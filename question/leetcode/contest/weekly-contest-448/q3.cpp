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
        int minTravelTime(int l, int n, int k, vector<int>& ps, vector<int>& ts) {
            vvvl dp(n, vvl(k+1, vl(k+1, INT_MAX)));

            dp[0][0][0] = 0;

            rep(i,0,n){
                rep(j,0,k+1){
                    int pi = i-j-1;
                    if(pi<0) break;
                    rep(l,0,k+1){
                        if(j+l>k) break;
                        int t = 0;
                        rep(m,0,k+1){
                            if(pi-m<0) break;
                            t+=ts[pi-m];
                            if(dp[pi][l][m]==INT_MAX) continue;
                            // cout << i << " " << j+l << " " << j << " " << pi << ' ' << m << " " << dp[pi][l][m] << " " << t << " " << ps[i] << " " << ps[pi] << endl;
                            dp[i][j+l][j] = min(dp[i][j+l][j], dp[pi][l][m] + t*(ps[i]-ps[pi]));
                        }
                    }
                }
            }

            // rep(i,0,n){
            //     rep(j,0,k+1){
            //         rep(l,0,k+1){
            //             cout << i << ' ' << j << ' ' << l << " " << dp[i][j][l] << endl;
            //         }cout << endl;
            //     }cout << endl;
            // }cout << endl;

            return *min_element(all(dp[n-1][k]));
        }
    };