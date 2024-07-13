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
    int minimumOperations(vector<vector<int>>& v) {
        ll n = v.size(), m = v[0].size();

        vll dp(3, {0,-1});

        rep(j,0,m){
            vll d(10);
            rep(k,0,10){
                d[k].s = k;
            }
            rep(i,0,n){
                d[v[i][j]].f++;
            }

            sort(rall(d));

            // rep(k,0,10){
            //     cout << d[k].f << " " << d[k].s << endl;
            // }

            // cout << d[0].f << endl;
            // cout << m << " " << m-d[0].f << ' ' << m-d[1].f << endl;

            ll s1 = LONG_LONG_MAX, s2 = LONG_LONG_MAX, s3 = LONG_LONG_MAX;
            if(dp[0].s != d[0].s) s1 = min(s1, dp[0].f+n-d[0].f);
            if(dp[1].s != d[0].s) s1 = min(s1, dp[1].f+n-d[0].f);
            if(dp[2].s != d[0].s) s1 = min(s1, dp[2].f+n-d[0].f);

            if(dp[0].s != d[1].s) s2 = min(s2, dp[0].f+n-d[1].f);
            if(dp[1].s != d[1].s) s2 = min(s2, dp[1].f+n-d[1].f);
            if(dp[2].s != d[1].s) s2 = min(s2, dp[2].f+n-d[1].f);

            if(dp[0].s != d[2].s) s3 = min(s3, dp[0].f+n-d[2].f);
            if(dp[1].s != d[2].s) s3 = min(s3, dp[1].f+n-d[2].f);
            if(dp[2].s != d[2].s) s3 = min(s3, dp[2].f+n-d[2].f);
            
            dp[0] = {s1, d[0].s};
            dp[1] = {s2, d[1].s};
            dp[2] = {s3, d[2].s};
        }

        return min({dp[0].f, dp[1].f, dp[2].f});
    }
};
