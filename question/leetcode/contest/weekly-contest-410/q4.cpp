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
    int countOfPairs(vector<int>& v) {
        ll n = v.size(), m = 1001;

        vvl dp(n, vl(m));

        rep(i,0,v[0]+1){
            dp[0][i] = 1;
        }

        rep(i,1,n){
            ll prev_min = -1;
            ll prev_max = v[i-1]+1;

            ll t = 0;

            rep(j,0,v[i]+1){
                ll cur_min = j;
                ll cur_max = v[i] - cur_min;

                while(prev_min+1 <= cur_min and prev_max-1 >= cur_max){
                    prev_min++;
                    prev_max--;
                    t+=dp[i-1][prev_min];
                    t%=mod;
                }

                dp[i][cur_min] = t;
            }

        }

        return accumulate(all(dp.back()), 0, [](auto a, auto b){return (a+b)%mod;});
    }
};
