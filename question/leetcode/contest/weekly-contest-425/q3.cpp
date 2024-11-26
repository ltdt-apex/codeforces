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
    int minArraySum(vector<int>& v, int sub, int op1, int op2) {
        int n = v.size();
        int s = accumulate(all(v), 0);
        int a = s;

        vvi dp(op1+1, vi(op2+1, s));

        rep(k,0,n){
            vvi ndp = dp;

            rep(i,0,op1+1){
                rep(j,0,op2+1){
                    if(i-1>=0) ndp[i][j] = min(ndp[i][j], dp[i-1][j]-v[k]/2);
                    if(j-1>=0 and v[k]>=sub) ndp[i][j] = min(ndp[i][j], dp[i][j-1]-sub);
                    if(i-1>=0 and j-1>=0 and ceild(v[k],2) >= sub) ndp[i][j] = min(ndp[i][j], dp[i-1][j-1]-v[k]/2-sub);
                    if(i-1>=0 and j-1>=0 and v[k] >= sub) ndp[i][j] = min(ndp[i][j], dp[i-1][j-1]-sub-(v[k]-sub)/2);
                    a = min(a, ndp[i][j]);
                }
            }

            dp = move(ndp);

            // rep(i,0,op1+1){
            //     rep(j,0,op2+1){
            //         cout << dp[i][j] << " ";
            //     }cout << endl;
            // }cout << endl;
        }

        return a;
    }
};
