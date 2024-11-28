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

    int minimumObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        deque<tiii> q;
        q.pb({0,0,0});
        vvi seen(n, vi(m));
        seen[0][0] = 1;

        while(not q.empty()){
            int i,j,d;
            tie(i,j,d) = q.front();
            q.pop_front();

            if(i==n-1 and j==m-1) return d;

            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;

                if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj]) continue;
                seen[ni][nj] = 1;

                if(v[ni][nj]==1) q.pb({ni,nj,d+1});
                else q.push_front({ni,nj,d});
            }
        }

        return -1;
    }
};