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
    vvvi dp;
    vi v;
    vector<char> o;
    vi dfs(int l, int r){
        // cout << l << " " << r << endl;
        if(dp[l][r].size()) return dp[l][r];
        if(l==r){
            dp[l][r].pb(v[l]);
            return dp[l][r];
        }

        rep(i,l,r){
            vi lv = dfs(l,i);
            vi rv = dfs(i+1,r);

            for(auto x: lv){
                for(auto y: rv){
                    if(o[i]=='+') dp[l][r].pb(x+y);
                    if(o[i]=='-') dp[l][r].pb(x-y);
                    if(o[i]=='*') dp[l][r].pb(x*y);
                }
            }
        }

        return dp[l][r];
    }

    vector<int> diffWaysToCompute(string s) {
        ll j = 0;
        ll n = s.size();
        s+="n";
        ll m = 0;


        while(true){
            ll num = 0;
            while(s[j]>='0' and s[j]<='9'){
                num*=10;
                num+=s[j]-'0';
                j++;
            }
            v.pb(num);
            if(s[j]=='n') break;
            o.pb(s[j]);
            j++;
        }

        n = v.size();
        dp.assign(n, vvi(n));

        return dfs(0,n-1);
    }
};