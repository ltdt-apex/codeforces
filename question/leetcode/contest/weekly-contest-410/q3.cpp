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
        vvl dp1(51, vl(2));
        vvl dp2(51, vl(2));

        rep(i,0,v[0]+1){
            dp1[i][0] = i+1;
            dp2[v[0]-i][0] = i+1;
        }
        rep(i,0,51){
            cout << dp1[i][0] << " ";
        }cout <<endl;
        rep(i,0,51){
            cout << dp2[i][0] << " ";
        }cout <<endl;
        ll alt = 0;
        rep(i,1,v.size()){
            ll x = v[i];
            alt++;
            alt%=2;
            ll t = 0;
            ll t1 = 0;
            ll t2 = 0;

            t1 = dp1[x][(alt+1)%2];
            if(t1==0) t1 = dp1[v[i-1]][(alt+1)%2];
            t2 = dp2[0][(alt+1)%2];
            if(t2==0) t2 = dp2[0][(alt+1)%2];

            // rep(i,0,51){
            //     t1+=dp1[i][(alt+1)%2];
            //     t2+=dp2[i][(alt+1)%2];
            //     // t += min(dp1[i][(alt+1)%2], dp2[x-i][(alt+1)%2]);
            // }

            t = min(t1,t2);
            // ll t = min(dp1[x][(alt+1)%2], dp2[0][(alt+1)%2]);
            rep(i,0,x+1){
                dp1[x-i][alt] = t;
                dp2[i][alt] = t;

                if (dp1[x-i][(alt+1)%2] == 0) t-= dp2[i][(alt+1)%2];
                else if (dp1[x-i][(alt+1)%2] == 0) t-= dp2[i][(alt+1)%2];
                else t -= min(dp1[x-i][(alt+1)%2], dp2[i][(alt+1)%2]);
                t = (t+mod) % mod;
            }

            rep(i,0,x+1){
                cout << dp1[i][alt] << " ";
            }cout <<endl;
            rep(i,0,x+1){
                cout << dp2[i][alt] << " ";
            }cout << endl;

        }

        ll a = 0;
        // rep(i,0,v.back()+1){
        //     a+= min(dp1[i][alt], dp2[v.back()-i][alt]);
        //     a%=mod;
        // }

        return a;
    }
};
