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

            
int factorial(int n) {
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int comb(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n - k));
}


class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        ll m = ceild(n,2);
        vector<vector<set<vector<int>>>> dp(m+1, vector<set<vector<int>>>(k));

        dp[0][0].insert(vi(0));

        rep(i,0,m){
            rep(j,0,10){
                ll r = 0;
                r += j*pow(10,n-1-i);
                r%=k;
                if(i!=m-1 or n%2==0) r += j*pow(10,i);
                r%=k;

                rep(l,0,k){
                    // if(i==0 and l!=0) continue;
                    ll nr = (r+l)%k;
                    for(auto v: dp[i][l]){
                        if(i==0 and j==0) continue;
                        if(i!=m-1 or n%2==0) v.pb(j);
                        v.pb(j);
                        sort(all(v));
                        // if(v[1] == 0) continue;
                        dp[i+1][nr].insert(v);
                    }
                }
            }
        }

        ll a = 0;
        
        for(auto v: dp[m][0]){
            // for (auto x: v){
            //     cout << x << " ";
            // }
            // cout << endl;
            unordered_map<int,int> map;
            for(auto x:v){
                map[x]++;
            }
            ll b = v.size();

            ll c = 1;
            rep(i,1,b+1) c*=i;
            for(auto [k,v]: map){
                rep(i,1,v+1) c/=i;
            }

            if(map[0]){
                b-=1;
                map[0]--;
                ll c0 = 1;
                rep(i,1,b+1) c0*=i;
                for(auto [k,v]: map){
                    rep(i,1,v+1) c0/=i;
                }

                c-=c0;
            }
            a+=c;
        }

        return a;
    }
};

