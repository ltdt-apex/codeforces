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
    int maxRectangleArea(vector<vector<int>>& v) {
        int n = v.size();

        int a = -1;

        rep(i,0,n){
            rep(j,0,n){
                if(i==j) continue;
                rep(k,0,n){
                    if(i==k or j==k) continue;
                    rep(l,0,n){
                        if(i==l or j==l or k==l) continue;

                        pii p1 = {v[i][0], v[i][1]};
                        pii p2 = {v[j][0], v[j][1]};
                        pii p3 = {v[k][0], v[k][1]};
                        pii p4 = {v[l][0], v[l][1]};

                        if(p1.s != p2.s) continue;
                        if(p3.s != p4.s) continue;
                        if(p2.f != p4.f) continue;
                        if(p1.f != p3.f) continue;
                        if(p1.f >= p2.f) continue;
                        if(p2.s >= p4.s) continue;

                        int valid = 1;
                        rep(b,0,n){
                            if(b==i or b==j or b==k or b==l) continue;

                            pii px = {v[b][0], v[b][1]};

                            if(p1.s <= px.s and px.s <= p3.s and p3.f<=px.f and px.f<=p4.f) valid = 0;
                        }

                        if(valid){
                            a = max(a, (p3.s-p1.s)*(p2.f-p1.f));
                        }
                    }
                }
            }
        }

        return a;
    }
};

