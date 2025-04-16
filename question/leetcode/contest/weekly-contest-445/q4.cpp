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
    int countNumbers(string l, string r, int b) {
        vi v1;
        vi v2;
        for(auto x: l) v1.pb(x-'0');
        for(auto x: r) v2.pb(x-'0');

        // find l with base b and r with base b
        auto f = [&](vi& v){
            vi ans;
            while(v.size()){
                // for(auto x: v){
                //     cout << x << " ";
                // }cout << endl;
                vi nv;
                int r = 0;
                for(auto x: v){
                    r=r*10+x;
                    if(r/b or nv.size()!=0) nv.pb(r/b);
                    r=r%b;
                }

                v = move(nv);
                ans.pb(r);
            }

            reverse(all(ans));
            return ans;
        };

        vi b1 = f(v1);
        vi b2 = f(v2);

        // for(auto x: b1){
        //     cout << x << " ";
        // }cout << endl;
        // for(auto x: b2){
        //     cout << x << " ";
        // }cout << endl;

        // use dp to find no. of non-decreasing digits
        // loop i=0...n, i = current loop digit, 
        // i=0 means first digit
        // i=n-1 means last digit
        
        // dp[j][0] = no. of non-decreasing digits can be from using first i-th digits 
        // (without restriction)
        // dp[j][1] = no. of non-decreasing digits can be from using first i-th digits 
        // (with restriction)
        // restriction = the next digit i+1 can not surpass v[i+1], 
        // because all digit from 0...i is the same as v[0...i]
        
        auto f2 = [&](vi& v){
            int n = v.size();
            vvl dp(b, vl(2));

            dp[0][1] = 1;

            rep(i,0,n){
                vvl ndp(b, vl(2));
                ll c1 = 0;
                ll c2 = 0;
                rep(j,0,b){
                    c1+=dp[j][0];
                    c2+=dp[j][1];
                    
                    ndp[j][0]+=c1;
                    if(j<v[i]) ndp[j][0]+=c2;
                    if(j==v[i]) ndp[j][1]+=c2;
                    ndp[j][0]%=mod;
                    ndp[j][1]%=mod;
                }

                // rep(j,0,b){
                //     cout << ndp[j][0] << " " << ndp[j][1] << endl;
                // }
                // cout << endl;

                dp = move(ndp);
            }

            ll a = 0;
            rep(i,0,b){
                a+=dp[i][0];
                a%=mod;
                a+=dp[i][1];
                a%=mod;
            }

            return a;
        };

        ll a1 = f2(b1);
        ll a2 = f2(b2);

        // cout << a1 << endl;
        // cout << a2 << endl;
        int ok = 1;
        rep(i,1,b1.size()){
            if(b1[i]<b1[i-1]) ok = 0;
        }

        return (a2-a1+ok+mod)%mod;

        // return 0;
    }
};
