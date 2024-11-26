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
    vii d2 = {{1,-1}, {1,0}, {1,1}};
    vii d3 = {{-1,1}, {0,1}, {1,1}};

    int maxCollectedFruits(vector<vector<int>>& v) {
        int n = v.size();

        vvi dp(n, vi(n, 0));

        rep(i,0,n){
            dp[i][i] = v[i][i];
            if(i>=1) dp[i][i] += dp[i-1][i-1];
        }

        rep(i,0,n){
            rep(j,max(n-i-1,i),n){
                if(i==j) continue;
                int m = 0;

                if(i-1>=0 and j-1>=0) m = max(m, dp[i-1][j-1]);
                if(i-1>=0) m = max(m, dp[i-1][j]);
                if(i-1>=0 and j+1<n) m = max(m, dp[i-1][j+1]);

                dp[i][j] = m;
                dp[i][j] += v[i][j];
            }
        }

        rep(j,0,n){
            rep(i,max(n-j-1,j),n){
                if(i==j) continue;

                int m = 0;

                if(j-1>=0 and i-1>=0) m = max(m, dp[i-1][j-1]);
                if(j-1>=0) m = max(m, dp[i][j-1]);
                if(j-1>=0 and i+1<n) m = max(m, dp[i+1][j-1]);

                dp[i][j] = m;
                dp[i][j] += v[i][j];
            }
        }

        return dp[n-1][n-1] + dp[n-1][n-2] + dp[n-2][n-1];
    }
};

