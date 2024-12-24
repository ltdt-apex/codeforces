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

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    int makeStringGood(string s) {
        vi v(26);
        rep(i,0,s.size()){
            v[s[i]-'a']++;
        }

        int m = *max_element(all(v));

        ll a = LONG_LONG_MAX;

        rep(j,0,m+1){
            ll dp1 = 0;
            ll dp2 = 0;
            ll dp1f = 0;
            ll dp2f = 0;
            rep(i,0,26){
                ll ndp1 = 0;
                ll ndp2 = 0;
                ll ndp1f = 0;
                ll ndp2f = 0;
                if(v[i]>j){
                    ndp1 = min(dp1,dp2)+v[i]-j;
                    ndp2 = min(dp1,dp2)+v[i];
                    ndp1f = v[i]-j;
                    ndp2f = v[i];
                }
                else{
                    ndp1 = min(max(0LL,j-v[i]-dp1f) + dp1, max(0LL,j-v[i]-dp2f) + dp2);
                    ndp2 = min(dp1,dp2) + v[i];
                    ndp1f = 0;
                    ndp2f = v[i];
                }
                dp1 = ndp1;
                dp2 = ndp2;
                dp1f = ndp1f;
                dp2f = ndp2f;
                // cout << j << " " << char('a'+i) << " " << dp1 << " " << dp2 << " " << dp1f << " " << dp2f << endl;
            }


            a = min({a, dp1, dp2});
        }

        return a;
    }
};

