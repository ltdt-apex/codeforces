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

    vii dirs = {{0,-1},{0,1},{1,0},{-1,0}};

    int minTimeToReach(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        set<tiii> s;
        s.insert({0,0,0});
        vvi d(n, vi(m, INT_MAX));

        while(not s.empty()){
            int t,i,j;
            tie(t,i,j) = *s.begin();

            // cout << t << ' ' << i << " " << j << endl;

            s.erase(s.begin());

            if(i==n-1 and j==m-1) return t;

            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m or max(t,v[ni][nj])+1 >= d[ni][nj]) continue;
                s.erase({d[ni][nj], ni, nj});
                d[ni][nj] = max(t,v[ni][nj])+1;
                s.insert({d[ni][nj], ni, nj});
            }
        }

        return 0;
    }
};

