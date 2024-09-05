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
    vvl dp;
    ll p; // preceding star

    int dfs(ll i, ll j, string& s, string& t){
        // cout << i << ' ' << j << endl;
        // cout << s[i] << " " << t[j] << endl;
        if(i==-1 and j<=p) return 1;
        if(i==-1 and j>p) return 0;
        if(i!=-1 and j==-1) return 0;
        if(i!=-1 and j<=p) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j] = 0;

        if(t[j] == '?'){
            dp[i][j] = dfs(i-1,j-1,s,t);
        }
        else if(t[j]=='*'){
            dp[i][j] |= dfs(i,j-1,s,t) || dfs(i-1,j,s,t) || dfs(i-1,j-1,s,t);
        }
        else{
            // cout << 'hi' << endl;
            dp[i][j] = (s[i]==t[j]) and dfs(i-1,j-1,s,t);
        }

        return dp[i][j];
    }

    bool isMatch(string s, string t) {
        n = s.size();
        m = t.size();
        dp.assign(n, vl(m, -1));

        p = -1;
        rep(i,0,m){
            if(t[i]!='*') break;
            p = i;
        }

        return dfs(n-1,m-1,s,t);
    }
};