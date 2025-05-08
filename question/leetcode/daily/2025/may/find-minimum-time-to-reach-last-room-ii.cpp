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

// class Solution {
// public:
//     int minTimeToReach(vector<vector<int>>& v) {
//         int n = v.size();
//         int m = v[0].size();

//         vvvi seen(n, vvi(m, vi(2)));

//         seen[0][0][1] = 1;

//         priority_queue<tiiii, vector<tiiii>, greater<tiiii>> q;
//         q.push({0,1,0,0});

//         while(not q.empty()){
//             int i,j,t,dt;
//             tie(t,dt,i,j) = q.top(); q.pop();

//             // cout << i << " " << j << endl;

//             if(i==n-1 and j==m-1) return t;

//             for(auto [di,dj]: dirs){
//                 int ni = i+di;
//                 int nj = j+dj;

//                 int ndt = dt==1 ? 2 : 1;
//                 int ndti = ndt == 2 ? 1 : 0;

//                 if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj][ndti]==1) continue;

//                 seen[ni][nj][ndti] = 1;
//                 q.push({max(t,v[ni][nj])+dt,ndt,ni,nj});
//             }
//         }

//         return -1;
//     }
// };



class Solution {
    public:
        /*
        using the fact that 
            you can only move to (i+j)%2==1 cell in odd moves
            you can only move to (i+j)%2==0 cell in even moves
        */
        int minTimeToReach(vector<vector<int>>& v) {
            int n = v.size();
            int m = v[0].size();
    
            vvi seen(n, vi(m));
    
            seen[0][0] = 1;
    
            priority_queue<tiii, vector<tiii>, greater<tiii>> q;
            q.push({0,0,0});
    
            while(not q.empty()){
                int i,j,t;
                tie(t,i,j) = q.top(); q.pop();
    
                // cout << i << " " << j << endl;
    
                if(i==n-1 and j==m-1) return t;
    
                for(auto [di,dj]: dirs){
                    int ni = i+di;
                    int nj = j+dj;
                    int dt = (i+j)%2==0 ? 1 : 2;
    
                    if(ni<0 or nj<0 or ni>=n or nj>=m or seen[ni][nj]==1) continue;
    
                    seen[ni][nj] = 1;
                    q.push({max(t,v[ni][nj])+dt,ni,nj});
                }
            }
    
            return -1;
        }
    };
