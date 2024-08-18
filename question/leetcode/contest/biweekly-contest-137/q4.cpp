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
    long long maximumValueSum(vector<vector<int>>& v) {
        ll n = v.size(), m = v[0].size();

        vvll dp(n);
        vlll top7;
        rep(i,0,n){
            vll t(m);
            rep(j,0,m){
                t[j] = {v[i][j],j};
            }
            sort(rall(t));

            rep(j,0,3){
                dp[i].pb(t[j]);
                top7.pb({t[j].f, i, t[j].s});
            }
        }

        sort(rall(top7));

        ll a = -LONG_LONG_MAX;

        rep(i1,0,n){
            for(auto [a1,j1]: dp[i1]){
                rep(i2,0,n){
                    if(i2==i1) continue;
                    for(auto [a2,j2]: dp[i2]){
                        if(j1==j2) continue;

                        rep(p,0,7){
                            auto[a3, i3, j3] = top7[p];
                            if(i3 == i1 or i3 == i2 or j3 == j1 or j3 == j2) continue;
                            a = max(a, a1+a2+a3);
                        }
                    }
                }
            }
        }

        return a;
    }   
};

