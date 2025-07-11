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
    long long gridGame(vector<vector<int>>& v) {
        // after bot 1 take the path, the only thing bot 2 can do is either 
        // 1. go till end of first row and then go down, or
        // 2. go down at first step, then go till end.
        // all other step is suboptimal
        // this leads to a O(n) solution with prefix sum setup, 
        // where n comes from full search on every possible bot 1 move.

        int m = v[0].size();

        vl p1(m+1);
        vl p2(m+1);

        rep(i,0,m){
            p1[i+1] = p1[i] + v[0][i];
            p2[i+1] = p2[i] + v[1][i];
        }

        ll a = LONG_LONG_MAX;

        rep(i,0,m){
            a = min(a, max(p1[m]-p1[i+1], p2[i]));
        }

        return a;
    }
};

