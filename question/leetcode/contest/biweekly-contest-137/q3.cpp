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
        rep(i,0,n){
            vll t(m);
            rep(j,0,m){
                t[j] = {v[i][j],j};
            }
            sort(all(t));

            rep(j,0,3){
                dp[i].pb(t[m-1-j]);
            }
        }

        ll a = -LONG_LONG_MAX;

        rep(i,0,n){
            rep(j,0,3){
                auto [a1,b] = dp[i][j];
                rep(l,0,n){
                    if(i==l) continue;
                    rep(o,0,3){
                        auto [a2,c] = dp[l][o];
                        if(b==c) continue; 
                        rep(p,0,n){
                            if(p==i or p==l) continue;
                            rep(q,0,3){
                                auto[a3,d] = dp[p][q];
                                if(d==b or d==c) continue;
                                a = max(a, a1+a2+a3);
                            }
                        }
                    }
                }
            }
        }

        return a;
    }   
};

