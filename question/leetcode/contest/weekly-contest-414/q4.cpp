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
    vii m = {{-1,-2}, {1,-2}, {-1,2}, {1,2}, {2,1}, {-2,1}, {2,-1}, {-2,-1}};

    ll dfs2(ll i, ll j, map<pii, vvl>&dp, vvl& dp2, ll p, int kx, int ky, vvi& v, ll n){
        // cout << i << ' ' << j << endl;
        if(j==0) return 0;
        if (dp2[i][j]!=-1) return dp2[i][j];

        ll m;
        if(p==0) m = -1;
        if(p==1) m = LONG_LONG_MAX; 

        ll cx=v[i][0];
        ll cy=v[i][1];

        rep(k,0,n-1){
            if((1<<k) & j){
                ll px = v[k][0];
                ll py = v[k][1];

                ll s = dp[{cx,cy}][px][py];
                  
                if(p==0) m = max(m, s+dfs2(k,j-(1<<k),dp,dp2,1-p,kx,ky,v,n));
                if(p==1) m = min(m, s+dfs2(k,j-(1<<k),dp,dp2,1-p,kx,ky,v,n));
            }
        }

        return dp2[i][j] = m;
    }

    int maxMoves(int kx, int ky, vector<vector<int>>& v) {
        map<pii, vvl> dp;
        v.pb({kx,ky});

        ll n = v.size();

        rep(k,0,n){
            ll i = v[k][0];
            ll j = v[k][1];
            vvl sdp(50, vl(50, -1));
            sdp[i][j] = 0;
            deque<pii> q;
            q.pb({i,j});

            while(not q.empty()){
                auto [i,j] = q.front();
                q.pop_front();
                for(auto [di, dj]: m){
                    ll ii = i+di;
                    ll jj = j+dj;

                    if(ii<0 or ii>=50 or jj<0 or jj>=50 or sdp[ii][jj]!=-1) continue;
                    sdp[ii][jj] = sdp[i][j]+1;
                    q.pb({ii,jj});
                }
            }

            // rep(ii,0,5){
            //     rep(jj,0,5){
            //         cout << sdp[ii][jj] << " ";
            //     }cout << endl;
            // }cout << endl;

            dp[{i,j}] = sdp;
        }


        vvl dp2(n, vl((1<<(n-1)), -1));

        return dfs2(n-1,(1<<(n-1))-1,dp,dp2,0,kx,ky,v,n);
    }
};