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
    vvi dp;
    vii p;

    int dfs(ll i, ll j){
        if(i<0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        dp[i][j] = 0;
        dp[i][j] = max(dp[i][j], dfs(i-1,j));

        if (not (j & (1 << p[i].s))){
            ll k = i;
            while(k>=0 and p[i].f == p[k].f) k--;
            dp[i][j] = max(dp[i][j], p[i].f + dfs(k,j|(1<<p[i].s)));
        }

        return dp[i][j];
    }

    int maxScore(vector<vector<int>>& v) {
        ll n = v.size();
        ll m = v[0].size();


        rep(i,0,n){
            rep(j,0,m){
                p.pb({v[i][j], i});
            }
        }

        sort(all(p));

        dp.assign(p.size(), vi(pow(2,n)+1, -1));

        return dfs(p.size()-1, 0);
    }
};