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
    vvl dp;
    int n;
    int s;

    int dfs(int i, int j, vi& v){
        if(i==-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int t = 0;
        rep(k,0,n){
            if(not ((1<<k)&j)) t+=v[k];
        }
        int r = s - (t%s);
        // cout << i << " " << j << endl;
        // cout << r << endl;

        int a = 0;
        rep(k,0,n){
            int x = (1<<k);
            if(x&j){
                if(r-v[k]<0) continue;
                else if(r-v[k]==0) a |= dfs(i-1,j-x,v);
                else a |= dfs(i,j-x,v);
            }
        }

        return dp[i][j] = a;
    }

    bool makesquare(vector<int>& v) {
        n = v.size();
        dp.assign(4, vl(1<<n, -1));

        s = accumulate(all(v), 0);
        if(s%4) return false;
        s/=4;
        return dfs(3, (1<<n)-1, v);
    }
};