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
    int possibleStringCount(string w, int k) {
        vl s;
        int n = w.size();
        w+='#';

        int c = 0;
        int last = w[0];

        rep(i,0,n+1){
            if(last != w[i]){
                s.pb(c);
                c=1;
                last = w[i];
            }
            else{
                c++;
            }
        }

        ll a = 1;
        ll m = s.size();
        // cout << m << endl;
        rep(i,0,m){
            // cout << s[i] << endl;
            a*=s[i];
            a%=mod;
        }

        if(m>=k){
            return a;
        }

        // cout << a << endl;

        vvl dp(m+1, vl(k));
        dp[0][0] = 1;

        rep(i,1,m+1){
            ll t = 0;
            rep(r,1,k){
                t+=dp[i-1][r-1];
                t%=mod;

                dp[i][r] = t;

                if(r-s[i-1]>=0) t=(t+mod-dp[i-1][r-s[i-1]])%mod;
            }
        }

        ll count = 0;

        rep(i,1,k){
            count+=dp[m][i];
            count%=mod;
        }

        return (a-count+mod)%mod;
    }
};

