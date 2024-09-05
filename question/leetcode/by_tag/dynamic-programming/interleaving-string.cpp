// @prefix template
// @description 

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
    ll n,m,k;
    vvl dp;

    int dfs(ll i, ll j, string& s1, string& s2, string& s3){
        if(dp[i][j]!=-1) return dp[i][j];

        ll p1 = 0, p2 = 0;
        ll k = i+j;
        if(i>0 and s1[i-1] == s3[k-1]) p1 = dfs(i-1,j,s1,s2,s3);
        if(j>0 and s2[j-1] == s3[k-1]) p2 = dfs(i,j-1,s1,s2,s3);

        return dp[i][j] = p1 | p2;
    }

    bool isInterleave(string s1, string s2, string s3) {
        n = s1.size();
        m = s2.size();
        k = s3.size();

        if(n+m!=k) return false;

        dp.assign(n+1, vl(m+1, -1));
        dp[0][0] = 1;

        return dfs(n, m, s1, s2, s3);
    }
};