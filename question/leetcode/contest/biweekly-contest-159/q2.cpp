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
    long long maxArea(vector<vector<int>>& v) {
        int n = v.size();

        int xma = v[0][0];
        int xmi = v[0][0];
        int yma = v[0][1];
        int ymi = v[0][1];
        
        rep(i,0,n){
            xma = max(xma, v[i][0]);
            xmi = min(xmi, v[i][0]);
            yma = max(yma, v[i][1]);
            ymi = min(ymi, v[i][1]);
        }

        ll a = -1;
        
        sort(all(v));
        int lx = v[0][0];
        int ly = v[0][1];
        rep(i,0,n){
            int x = v[i][0];
            int y = v[i][1];

            if(x!=lx){
                lx = x;
                ly = y;
            }

            if(y!=ly and max(xma-x,x-xmi)!=0){
                a = max(a, (ll)(y-ly)*max(xma-x,x-xmi));
            }
        }

        sort(all(v), [&](const auto &x, const auto &y){
            if(x[1]==y[1]) return x[0]<y[0];
            return x[1]<y[1];
        });

        lx = v[0][0];
        ly = v[0][1];
        rep(i,0,n){
            int x = v[i][0];
            int y = v[i][1];

            if(y!=ly){
                lx = x;
                ly = y;
            }

            if(x!=lx and max(yma-y,y-ymi)!=0){
                a = max(a, (ll)(x-lx)*max(yma-y,y-ymi));
            }
        }

        return a;

    }
};

