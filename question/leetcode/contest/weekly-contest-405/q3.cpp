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

void ps(pll& a, pll& b, ll x = 1){
    a.f += b.f * x;
    a.s += b.s * x;
}

 
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& v) {
        ll n = v.size(), m = v[0].size();

        vvll c(n, vll(m));


        rep(i,0,n){
            rep(j,0,m){
                if(i>0) ps(c[i][j], c[i-1][j]);
                if(j>0) ps(c[i][j], c[i][j-1]);
                if(i>0 and j > 0) ps(c[i][j], c[i-1][j-1], -1);
                if(v[i][j]=='X') c[i][j].f += 1;
                if(v[i][j]=='Y') c[i][j].s += 1;
            }
        }


        ll ans = 0;

        rep(i,0,n){
            rep(j,0,m){
                // cout << c[i][j].f << " " << c[i][j].s << " " << endl;
                if(c[i][j].f == c[i][j].s and c[i][j].f>=1){
                    ans++;
                }
            }
        }
        // cout << endl;

        return ans;
    }
};

