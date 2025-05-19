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
        int minMoves(vector<string>& v) {
            int n = v.size();
            int m = v[0].size();

            vvii map(26);
            vi used(26);
            
            rep(i,0,n){
                rep(j,0,m){
                    if(v[i][j]>='A' and v[i][j]<='Z'){
                        map[v[i][j]-'A'].pb({i,j});
                    }
                }
            }

            deque<pii> q;
            q.pb({0,0});
            vvi dis(n, vi(m, INT_MAX));
            dis[0][0] = 0;

            while(not q.empty()){
                auto [i,j] = q.front(); q.pop_front();

                if(i==n-1 and j==m-1) return dis[i][j];
                int d = dis[i][j];

                if(v[i][j]>='A' and v[i][j]<='Z' and not used[v[i][j]-'A']){
                    used[v[i][j]-'A']=1;
                    for(auto [ni,nj]: map[v[i][j]-'A']){
                        // cout << ni << " " << nj << endl;
                        if(dis[ni][nj]<=d) continue;
                        dis[ni][nj] = d;
                        q.push_front({ni,nj});
                    }
                }

                for(auto [di,dj]: dirs){
                    int ni = i+di;
                    int nj = j+dj;
                    if(ni<0 or nj<0 or ni>=n or nj>=m or v[ni][nj] == '#' or dis[ni][nj]<=1+d) continue;
                    dis[ni][nj] = 1+d;
                    q.pb({ni,nj});
                }
            }

            return -1;
        }
    };
