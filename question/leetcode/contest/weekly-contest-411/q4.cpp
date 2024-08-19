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
    vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>>& q) {
        ll n = s.size();

        ll l = 0;
        vl c(2);
        vl maxl(n);
        rep(r,0,n){
            c[s[r]-'0']++;
            while(c[0] > k and c[1] > k){
                c[s[l]-'0']--;
                l++;
            }
            maxl[r] = l;
        }

        // rep(i,0,n){
        //     cout << maxl[i] << " ";
        // } cout << endl;

        c.assign(2, 0);
        vl maxr(n);
        ll r = n-1;
        repr(l,n-1,-1){
            // cout << l << " " << r << " " << c[0] << " " << c[1] << endl;
            c[s[l]-'0']++;
            while(c[0] > k and c[1] > k){
                c[s[r]-'0']--;
                r--;
            }
            maxr[l] = r;
        }

        // rep(i,0,n){
        //     cout << maxr[i] << " ";
        // } cout << endl;

        vl ps(n+1);
        rep(i,1,n+1){
            ps[i] = ps[i-1] + ((i-1) - maxl[i-1] + 1);
        }

        // rep(i,0,n+1){
        //     cout << ps[i] << " ";
        // }cout << endl;

        ll m = q.size();
        vl a;
        rep(i,0,m){
            ll l = q[i][0], r = q[i][1];
            ll mr = min(r,maxr[l]);
            // cout << mr << endl;

            ll ans = (mr-l+2)*(mr-l+1)/2;
            // cout << ans << endl;
            ans += ps[r+1] - ps[mr+1];
            // cout << ans << endl;

            a.pb(ans);
        }

        return a;
    }
};

