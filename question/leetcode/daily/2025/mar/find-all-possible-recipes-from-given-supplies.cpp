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
        vector<string> findAllRecipes(vector<string>& rs, vector<vector<string>>& ins, vector<string>& ss) {
            int count = 0;
            unordered_map<string, int> d1;
            vector<string> d2;

            for(auto x: rs){
                if(d1.count(x)) continue;

                d1[x] = count;
                d2.push_back(x);
                count++;
            }
            int t = count;

            for(auto y: ins){
                for(auto x: y){
                    if(d1.count(x)) continue;
    
                    d1[x] = count;
                    d2.push_back(x);
                    count++;
                }
            }
            for(auto x: ss){
                if(d1.count(x)) continue;

                d1[x] = count;
                d2.push_back(x);
                count++;
            }

            vvi adj(count);
            vi ind(count);
            int m = ins.size();

            rep(i,0,m){
                for(auto x: ins[i]){
                    adj[d1[x]].pb(d1[rs[i]]);
                    ind[d1[rs[i]]]++;
                }
            }
        
            queue<int> q;

            for(auto x: ss){
                q.push(d1[x]);
            }

            vector<string> a;

            while(not q.empty()){
                int u = q.front(); q.pop();

                if(u<t) a.pb(d2[u]);

                for(auto v: adj[u]){
                    ind[v]--;
                    if(ind[v]==0) q.push(v);
                }
            }

            return a;

        }
    };