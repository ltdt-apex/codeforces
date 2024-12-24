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
    vector<int> leftmostBuildingQueries(vector<int>& v, vector<vector<int>>& qs) {
        int n = v.size();
        int m = qs.size();

        priority_queue<pii> q;

        rep(i,0,n){
            q.push({v[i],-i});
        }

        vvii nq(n);
        rep(i,0,m){
            int x = qs[i][0];
            int y = qs[i][1];

            if(x > y){
                swap(x,y);
            }

            // cout << x << " " << y << endl;
            nq[x].pb({y,i});
        }

        vi a(m);
        set<int> s;

        while(not q.empty()){
            auto [_,x] = q.top();
            q.pop();
            x = -x;
            s.insert(x);

            for(auto [y,j]: nq[x]){
                // cout << x << " " << y << endl;
                if(v[x]<v[y] or x==y) {
                    a[j] = y;
                }
                else{
                    auto e = s.upper_bound(y);
                    if(e==s.end()) a[j] = -1;
                    else a[j] = *e;
                }
            }
        }

        return a;
    }
};
