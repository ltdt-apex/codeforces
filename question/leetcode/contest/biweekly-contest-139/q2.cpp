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
    vii d = {{-1,0}, {1,0}, {0,-1}, {0,1}};

    bool findSafeWalk(vector<vector<int>>& v, int h) {
        deque<tiii> q;
        set<pii> seen;

        vvl dp;
        ll n = v.size();
        ll m = v[0].size();

        q.pb({0,0,v[0][0]});
        seen.insert({0,0});
        
        while(not q.empty()){
            tiii c = q.front();
            q.pop_front();

            ll i,j,z;
            tie(i,j,z) = c;
            // cout << i << " " << j << " " << z << endl;
            if(i==n-1 and j==m-1) return z < h;

            for (auto [di, dj]: d){
                ll ii = i+di;
                ll jj = j+dj;

                if(ii < 0 or jj < 0 or ii >= n or jj >= m or seen.count({ii,jj})) continue;
                if(v[ii][jj]==0) q.push_front({ii,jj,z});
                else q.push_back({ii,jj,z+1});
                seen.insert({ii,jj});
            }
        }

        return true;
    }
};
