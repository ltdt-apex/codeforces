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

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

class Solution {
public:
    int maximumInvitations(vector<int>& adj) {
        /*
        cycle problem,
        1. cycle with len > 2, they can't form with antoher group
        2. cycle with len = 2, they can form the table with other cycle len = 2, as well
        as chain that point to this two person in cycle,
        for example, A1 -> A2 -> A<->B <- B1 <- B2, C1 -> C2 -> C<->D <- D1 <- D2, 

        we can see that A and B, C and D form cycle with len=2 and A1 A2 form a chain to A, 
        and same for B,C,D 1 and 2, and we can see all people can sit together without conflict.
        for A1, A2, B1, B2, we can use topological sort to find them, 
        then the remaining are persons that form cycle.
        */

        int n = adj.size();
        vi in(n);
        stack<int> q;
        vi seen(n);
        vi c(n);

        rep(u,0,n){
            int v = adj[u];
            in[v]++;
        }

        rep(u,0,n){
            if(in[u]==0) q.push(u);
        }

        while(not q.empty()){
            int u = q.top();
            q.pop();
            seen[u]=1;

            int v = adj[u];
            in[v]--;
            c[v] = max(c[v], c[u]+1);
            if(in[v]==0)q.push(v);
        }

        int m = 0;
        int m2 = 0;

        rep(u,0,n){
            if(seen[u]) continue;
            int l = 0;
            int s = u;

            while(not seen[s]){
                l++;
                seen[s] = 1;
                s = adj[s];
            }

            if(l==2){
                // cout << s << " " << adj[s] << endl;
                // cout << c[s] << ' ' << c[adj[s]] << endl;
                m2+=2+c[s]+c[adj[s]];
            }
            else{
                m = max(m,l);
            }
        }

        // cout << m << " " << m2 << endl;

        return max(m,m2);

    }
};
