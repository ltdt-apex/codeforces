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

    void dfs(string cur, double v, unordered_map<string, double>& m, vector<vector<string>>& p, vector<double>& r){
        // cout << cur << endl;
        rep(i,0,p.size()){
            if(p[i][0] == cur){
                if(not m.count(p[i][1])){
                    m[p[i][1]] = v*r[i];
                    dfs(p[i][1], v*r[i],m,p,r);
                }
            }
            if(p[i][1] == cur){
                if(not m.count(p[i][0])){
                    m[p[i][0]] = v/r[i];
                    dfs(p[i][0], v/r[i],m,p,r);
                }
            }
        }
    }

    double maxAmount(string s, vector<vector<string>>& p1, vector<double>& r1, vector<vector<string>>& p2, vector<double>& r2) {
        unordered_map<string, double> map;

        dfs(s,1.0,map,p1,r1);
        map[s] = 1.0;

        double a = 0;

        for(auto [k,v]: map){
            unordered_map<string, double> map2;
            dfs(k,v,map2,p2,r2);
            map2[k] = v;
            for(auto [k,v]: map2){
                if(k == s) a = max(a,v);
            }
        }

        return a;
    }
};

