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

class Solution {
public:

    vii dirs = {{0,1},{0,-1},{-1,0},{1,0}};

    int minimumTime(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        if(v[0][1]>1 and v[1][0]>1) return -1;

        priority_queue<tiii, viii, greater<tiii>> q;
        q.push({0,0,0});
        vvi dp(n, vi(m,INT_MAX));
        dp[0][0] = 0;

        while(not q.empty()){
            auto [d,i,j] = q.top();
            q.pop();

            if(i==n-1 and j==m-1) return d;

            for(auto [di, dj]:dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m)continue;

                int nd;
                if(d+1>=v[ni][nj]) nd = d+1;
                else nd = v[ni][nj] + ((d+1)%2 != v[ni][nj]%2);

                if(nd<dp[ni][nj]){
                    dp[ni][nj] = nd;
                    q.push({nd,ni,nj});
                }
            }
        }

        return -1;
    }
};
