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
    ll n,m;
    vector<vector<vector<vector<ll>>>> dp;

    int dfs(ll i1, ll j1, ll i2, ll j2, string& s1, string& s2){
        // cout << i1 << " " << j1 << " " << i2 << " " << j2 << endl;
        if(i1==j1) return s1[i1] == s2[i2];
        if(dp[i1][j1][i2][j2]!=-1) return dp[i1][j1][i2][j2];

        dp[i1][j1][i2][j2] = 0;
        rep(i,i1,j1){
            ll li1 = i1, lj1 = i, ri1 = i+1, rj1 = j1;
            ll li2 = i2, lj2 = i2+(lj1-li1), ri2 = lj2+1, rj2 = j2;
            dp[i1][j1][i2][j2] |= dfs(li1,lj1,li2,lj2,s1,s2) and dfs(ri1,rj1,ri2,rj2,s1,s2);

            li2 = i2+(rj1-ri1+1), lj2 = j2, ri2 = i2, rj2 = i2+(lj1-li1+1);
            dp[i1][j1][i2][j2] |= dfs(li1,lj1,li2,lj2,s1,s2) and dfs(ri1,rj1,ri2,rj2,s1,s2);
        }

        return dp[i1][j1][i2][j2];
    }

    bool isScramble(string s1, string s2) {
        n = s1.size();
        dp.assign(n, vvvl(n, vvl(n, vl(n, -1))));

        return dfs(0,n-1,0,n-1,s1,s2);
    }
};