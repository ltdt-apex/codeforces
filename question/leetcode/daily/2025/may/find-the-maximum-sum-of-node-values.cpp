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


// class Solution {
//     public:
//         long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& es) {
//             int n = v.size();
//             int m = es.size();

//             vvi adj(n);
//             rep(i,0,m){
//                 int u = es[i][0];
//                 int v = es[i][1];

//                 adj[u].pb(v);
//                 adj[v].pb(u);
//             }

//             vll dp(n);

//             function<void(int,int)> dfs = [&](int u, int p){
//                 vvl sv;
//                 for(auto v: adj[u]){
//                     if(v==p) continue;

//                     dfs(v,u);

//                     sv.pb({dp[v].f-dp[v].s, dp[v].f, dp[v].s});
//                 }
//                 sort(rall(sv));

//                 int l = sv.size();
//                 ll mo = -1;
//                 if(l>0) mo = sv[0][1];

//                 int i = 1;
//                 for(;i+1<l;i+=2){
//                     if(sv[i][0]+sv[i+1][0]>0){
//                         mo+=sv[i][1]+sv[i+1][1];
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 for(;i<l;i++){
//                     mo+=sv[i][2];
//                 }

//                 ll me = 0;
//                 int j = 0;
//                 for(;j+1<l;j+=2){
//                     if(sv[j][0]+sv[j+1][0]>0){
//                         me+=sv[j][1]+sv[j+1][1];
//                     }
//                     else{
//                         break;
//                     }
//                 }
//                 for(;j<l;j++){
//                     me+=sv[j][2];
//                 }

//                 // cout << "test: " << mo << ' ' << me << ' ' << (v[u]^k) << endl;

//                 if(mo!=-1){
//                     dp[u].f = mo+v[u];
//                     dp[u].s = mo+(v[u]^k);
//                 }

//                 dp[u].f = max(dp[u].f, me+(v[u]^k));
//                 dp[u].s = max(dp[u].s, me+v[u]);
//             };

//             dfs(0,-1);

//             // rep(i,0,n){
//             //     cout << dp[i].f << ' ' << dp[i].s << endl;
//             // }

//             return dp[0].s;
//         }
//     };


class Solution {
public:
    long long maximumValueSum(vector<int>& v, int k, vector<vector<int>>& es) {
    /*
    A key observation is that after performing any number of operations, 
    the number of nodes with XOR to k is always even.

    Another important insight is that we can control which even-sized subset of nodes ends up with XOR k. 
    For example, consider the tree 1–2–3–4, and suppose we want nodes 1 and 4 to be XORed. 
    If we apply operations on edges 1–2, 2–3, and 3–4, 
    nodes 2 and 3 will each be involved in two operations, 
    so their changes cancel out. As a result, only nodes 1 and 4 are effectively flipped.

    Combining these observations, 
    we just need to find even-sized subset of nodes to be Xored with k 
    that created maximum answer.
    */
        ll a = 0;

        int mi = INT_MAX;
        int c = 0;
        int n = v.size();

        rep(i,0,n){
            if((v[i]^k)>v[i]){
                c++;
                a+=(v[i]^k);
            }
            else{
                a+=v[i];
            }
            mi = min(mi,abs((v[i]^k)-v[i]));
        }

        // cout << a << endl;
        // cout << c << endl;

        if(c%2)a-=mi;
        return a;
    }
};