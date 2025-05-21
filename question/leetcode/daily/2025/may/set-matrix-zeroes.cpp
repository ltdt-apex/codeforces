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
        void setZeroes(vector<vector<int>>& v) {
            int n = v.size();
            int m = v[0].size();
            int zeroRow = 0;
            int zeroCol = 0;

            rep(i,0,n){
                rep(j,0,m){
                    if(v[i][j]==0){
                        v[i][0] = 0;
                        v[0][j] = 0;
                        if(i==0) zeroRow = 1;
                        if(j==0) zeroCol = 1;
                    }
                }
            }

            rep(i,1,n){
                rep(j,1,m){
                    if(v[i][0]==0 or v[0][j]==0) v[i][j] = 0;
                }
            }

            if(zeroRow){
                rep(j,0,m) v[0][j] = 0;
            }
            if(zeroCol){
                rep(i,0,n) v[i][0] = 0;
            }
        }
    };