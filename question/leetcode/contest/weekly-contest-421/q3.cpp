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
    int subsequencePairCount(vector<int>& v) {
        ll n = v.size();
        ll m = *max_element(all(v));

        vvl dp(m+1, vl(m+1, 0));
        dp[0][0] = 1;

        rep(k,0,n){
            int x = v[k];
            vvl ndp(m+1, vl(m+1, 0));
            rep(i,0,m+1){
                rep(j,0,m+1){
                    ndp[gcd(i,x)][j] += dp[i][j];
                    ndp[gcd(i,x)][j] %= mod;
                    ndp[i][gcd(j,x)] += dp[i][j];
                    ndp[i][gcd(j,x)] %= mod;
                    ndp[i][j] += dp[i][j];
                    ndp[i][j] %= mod;
                }
            }

            dp = move(ndp);
        }

        ll a = 0;

        rep(i,1,m+1){
            a+=dp[i][i];
            a%=mod;
        }

        return a;
    }
};

