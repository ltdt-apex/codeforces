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
    int snakesAndLadders(vector<vector<int>>& v) {
        int n = v.size();

        vi dis(n*n+1, -1);        
        queue<int> q;
        q.push(1);
        dis[1] = 0;

        while(not q.empty()){
            int c = q.front(); q.pop();
            // cout << c << endl;
            if(c==n*n) return dis[n*n];

            rep(dc,1,7){
                int nc = c+dc;
                if(nc>n*n) continue;
                int i = n-1-(nc-1)/n;
                int iso = ((nc-1)/n)%2==0;
                int j = iso ? (nc-1)%n : n-1-(nc-1)%n;

                // cout << nc << " " << i << ' ' << j << endl;                
                if(v[i][j]!=-1) nc = v[i][j];
                if(dis[nc]!=-1) continue;
                dis[nc] = dis[c]+1;
                // cout << nc << " " << dis[c]+1 << endl;
                q.push(nc);
            }
        }

        return -1;
    }
};
