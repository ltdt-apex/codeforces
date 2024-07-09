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
#define ceild(a,b) (a)%(b) ? ((a)/(b) + 1) : (a)/(b)
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
 
const ll mod = 1e9 + 7;
 
const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;
 
const int lt = 32;
 


class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& q) {

        unordered_map <ll,ll> m;
        rep(i,0,q.size()){
            m[q[i][0]+1] = q[i][1];
        }

        vvl dp(n+1, vl((n+1)*(n+1)));
        if(m[1]!=0) return 0;

        dp[1][0] = 1;
        ll prev = 0;

        rep(i,2,n+1){
            ll cur = prev+i-1;

            ll t = 0;
            rep(j,0,cur+1){
                if(j<=prev) t+= dp[i-1][j];
                t%=mod;
                if(j-i>=0) t-=dp[i-1][j-i];
                t+=mod;
                t%=mod;

                // cout << i << ' ' << j << " " << t << endl;

                if(m.count(i) and m[i]!=j) continue;
                dp[i][j] = t;
            }

            prev = cur;
        }

        
        ll a = 0;
        rep(i,0,(n+1)*(n+1)){
            a += dp.back()[i];
            a%=mod;
        }

        // rep(i,0,n+1){
        //     rep(j,0,(n+1)*(n+1)){
        //         cout << dp[i][j] << " ";
        //     }cout << endl;
        // }
        // cout << endl;

        return a;
    }
};