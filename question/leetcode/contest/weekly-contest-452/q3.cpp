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
typedef tuple<int, int, int, int> tiiii;

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
    int minMoves(vector<string>& v, int e) {
        int n = v.size();
        int m = v[0].size();

        vvi id_(n, vi(m,-1));
        int c = 0;
        pii s;

        rep(i,0,n){
            rep(j,0,m){
                if(v[i][j]=='L'){
                    id_[i][j] = c;
                    c++;
                }
                if(v[i][j]=='S') s = {i,j};
            }
        }

        int dis[n][m][1<<c][e+1];
        int be[n][m][1<<c];
        memset(dis, -1, sizeof(dis));
        memset(be, -1, sizeof(be));

        queue<tiiii> q;
        q.push({s.f,s.s,0,e});
        dis[s.f][s.s][0][e] = 0;
        be[s.f][s.s][0] = 0;

        while(not q.empty()){
            int i,j,st,k;
            tie(i,j,st,k) = q.front(); q.pop();

            // cout << i << ' ' << j << " " << st << ' ' << k << " " << dis[i][j][st][k] << endl;

            if(st==(1<<c)-1) return dis[i][j][st][k];
            if(k==0) continue;
            
            int nd = dis[i][j][st][k]+1;
            for(auto [di,dj]: dirs){
                int ni = i+di;
                int nj = j+dj;
                int nk = k-1;
                int nst = st;

                if(ni<0 or nj<0 or ni>=n or nj>=m or v[ni][nj]=='X') continue;
                if(id_[ni][nj]!=-1) nst = st | 1<<id_[ni][nj];
                if(v[ni][nj]=='R') nk = e;
                
                if(be[ni][nj][nst]>=nk) continue;
                if(dis[ni][nj][nst][nk]!=-1) continue;

                be[ni][nj][nst] = nk;
                dis[ni][nj][nst][nk] = nd;
                q.push({ni,nj,nst,nk});
            }
        }

        return -1;
    }
};
