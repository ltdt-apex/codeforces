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

vii dirs = {{0,1},{0,-1},{1,0},{-1,0}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};


class Solution {
public:
    int minCost(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        deque<tiii> q;

        unordered_map<int, pii> map;
        map[1] = dirs[0];
        map[2] = dirs[1];
        map[3] = dirs[2];
        map[4] = dirs[3];

        q.pb({0,0,0});
        vvi td(n, vi(m, INT_MAX));
        td[0][0] = 0;

        while(not q.empty()){
            auto [i,j,d] = q.front();
            q.pop_front();
            // cout << i << " " << j << " " << d << endl;

            if(i==n-1 and j==m-1) return d;

            int o = v[i][j];

            auto [tdi, tdj] = map[o];
            
            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;
                int w = not (tdi==di and tdj==dj);

                // cout << d+w << endl;
                if(ni<0 or ni>=n or nj<0 or nj>=m or d+w >= td[ni][nj]) continue;

                td[ni][nj] = d+w;
                if(w==0){
                    q.push_front({ni,nj,d});
                }
                if(w==1){
                    q.pb({ni,nj,d+1});
                }
            }
        }

        return td[n-1][m-1];
    }
};