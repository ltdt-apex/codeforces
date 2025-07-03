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
#define range(i,b) for (int i = 0; i < b; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repr(i,a,b) for (int i = a; i > b; i--)
#define sq(a) (a)*(a)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define ceild(a,b) ((a)%(b) ? ((a)/(b) + 1) : (a)/(b))
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)

const ll mod = 1e9 + 7;

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};


class Solution {
public:
    int possibleStringCount(string s, int k) {
        s+='0';
        int n = s.size();

        vl cs;
        char l = s[0];
        int count = 0;

        rep(i,0,n){
            if(l!=s[i]){
                cs.pb(count);
                l = s[i];
                count = 0;
            }
            count++;
        }

        int m = cs.size();

        ll a = 1;
        for(auto x: cs){
            a*=x;
            a%=mod;
        }

        // cout << a << endl;

        if(m>=k){
            return a;
        }

        vl dp(k);
        dp[0] = 1;

        rep(i,0,m){
            vl ndp(k);
            int x = cs[i];
            ll t = 0;
            
            rep(j,1,k){
                t+=dp[j-1];
                t%=mod;

                ndp[j] = t;

                if(j-x>=0) {
                    t-=dp[j-x];
                    t+=mod;
                    t%=mod;
                }
            }

            dp = move(ndp);
            // rep(i,0,k){
            //     cout << dp[i] << ' ';
            // }
            // cout << endl;
        }

        rep(i,0,k){
            a-=dp[i];
            a+=mod;
            a%=mod;
        }

        return a;
    }
};