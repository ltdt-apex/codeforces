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
    int minFlips(vector<vector<int>>& v) {
        ll n = v.size();
        ll m = v[0].size();

        ll a = 0;

        rep(i,0,n/2){
            rep(j,0,m/2){
                ll x = v[i][j] + v[i][m-j-1] + v[n-i-1][j] + v[n-i-1][m-j-1];
                a+= min(x,4-x);
            }
        }

        ll d = 0;
        ll c = 0;

        if(n%2){
            ll i = n/2;
            rep(j,0,m/2){
                c += v[i][m-j-1] + v[i][j];
                if (v[i][m-j-1] != v[i][j]) d++;
            }
        }

        if(m%2){
            ll j = m/2;
            rep(i,0,n/2){
                c += v[i][j] + v[n-i-1][j];
                if (v[i][j] != v[n-i-1][j]) d++;
            }
        }

        a+=d;
        if(c%4==2 and d==0){
            a+=2;
        }

        if(n%2 and m%2){
            a+=v[n/2][m/2];
        }

        return a;
    }
};
