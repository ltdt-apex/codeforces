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
    vector<int> largestDivisibleSubset(vector<int>& v) {
        sort(all(v));
        ll n = v.size();
        vi dp(n,-1);
        vi count(n,1);

        ll m = 0;
        ll k = 0;

        rep(i,1,n){
            rep(j,0,i){
                if(v[i]%v[j]==0 and count[j]+1>count[i]){
                    dp[i] = j;
                    count[i] = count[j]+1;
                    if(count[i] > m){
                        m = count[i];
                        k = i;
                    }
                }
            }
        }

        vi ans;

        while(k!=-1){
            ans.pb(v[k]);
            k = dp[k];
        }

        return ans;
    }
};