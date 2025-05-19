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
    int colorTheGrid(int m, int n) {
        int k = pow(3,m);
        vl valid(k);
        vl dp(k);

        rep(i,0,k){
            int l = -1;
            int x = i;
            int ok = 1;

            rep(j,0,m){
                if(l==x%3) ok=0;
                l=x%3;
                x/=3;
            }

            // if(ok) cout << i << endl;

            dp[i] = ok;
            valid[i] = ok;
        }

        rep(i,1,n){
            vl ndp(k);

            rep(j,0,k){
                if(not valid[j]) continue;

                rep(l,0,k){
                    if(not valid[l]) continue;

                    int x = j;
                    int y = l;
                    int ok = 1;
        
                    rep(_,0,m){
                        if(x%3==y%3) ok=0;
                        x/=3;
                        y/=3;
                    }

                    // if(ok) cout << j << " " << l << endl;
        
                    if(ok) ndp[j]+=dp[l];
                    ndp[j]%=mod;
                }
            }

            dp = move(ndp);
        }

        ll a = 0;
        rep(i,0,k){
            a+=dp[i];
            a%=mod;
        }
        return a;
    }
};