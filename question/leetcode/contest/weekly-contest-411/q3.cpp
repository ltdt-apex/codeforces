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


int dfs(ll i, ll r, ll n, ll k, vvl& dp, vl& p){
    int m = (n+1)/2;
    if (i==m) return r==0 ? 1 : -1; 
    if(dp[i][r]!=-2) return dp[i][r];

    repr(j,9,-1){
        ll nr = r;
        nr += j*p[i];
        if(not(n%2 and i==m-1)){
            nr+=j*p[n-1-i];
        }
        nr %= k;
        if(dfs(i+1, nr, n, k, dp, p) != -1){
            return dp[i][r] = j;
        }
    }

    return dp[i][r] = -1;
}


class Solution {
public:
    string largestPalindrome(int n, int k) {
        // dp[i][r] = x mean the x = max value that can put in ith digit that able to form integer divisible by k
        // with r = current remainder of number mod k without using digits from i...n-i-1
        // -1 means no solution for this case
        // for example, dp[2][3] = 4 means, 
        // 4 is the maximum value that can put on abx...xba, 
        // where (a*10**(n-1) + b*10**(n-2) + b*10**(1) + a*10**(0)) mod k = 3
        vvl dp(n, vl(k, -2));

        // p[i] = (10**i)%k
        vl p(n);
        p[0] = 1;
        rep(i,1,n) p[i] = (10*p[i-1])%k;

        dfs(0,0,n,k,dp,p);

        string a(n, '0');
        ll r = 0;

        int m = (n+1)/2;
        rep(i,0,m){
            ll v = dp[i][r];
            a[i] = v + '0';
            a[n-1-i] = v + '0';

            r+=v*p[i];
            if(not(n%2 and i==m-1)){
                r+=v*p[n-1-i];
            }
            r%=k;
        }

        return a;
    }
};

