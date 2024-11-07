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
    int maxValue(vector<int>& v, int l) {
        ll n = v.size();
        vvvi dp1(n+1, vvi(l+1, vi(128)));
        vvvi dp2(n+1, vvi(l+1, vi(128)));

        dp1[0][0][0] = 1;
        rep(i,0,n){
            rep(j,0,l+1){
                rep(k,0,128){
                    if(dp1[i][j][k]){
                        dp1[i+1][j][k] = 1;
                        if(j+1<=l) dp1[i+1][j+1][k|v[i]] = 1;
                    }
                }
            }
        }

        reverse(all(v));
        dp2[0][0][0] = 1;
        rep(i,0,n){
            rep(j,0,l+1){
                rep(k,0,128){
                    if(dp2[i][j][k]){
                        dp2[i+1][j][k] = 1;
                        if(j+1<=l) dp2[i+1][j+1][k|v[i]] = 1;
                    }
                }
            }
        }

        int a = 0;

        rep(i,0,n){
            rep(j,0,128){
                rep(k,0,128){
                    if(dp1[i+1][l][j] and dp2[n-i-1][l][k]){
                        a = max(a,int(j^k));
                    }
                }
            }
        }

        return a;
    }
};
