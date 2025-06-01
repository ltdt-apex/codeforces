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
    vector<vector<int>> minAbsDiff(vector<vector<int>>& v, int k) {
        int n = v.size();
        int m = v[0].size();

        int s1 = n-k+1;
        int s2 = m-k+1;

        vvi a(s1, vi(s2));

        rep(i,0,s1){
            rep(j,0,s2){
                unordered_set<int> sv;
                rep(ii,i,i+k){
                    rep(jj,j,j+k){
                        sv.insert(v[ii][jj]);
                    }
                }
                
                vi svv(all(sv));
                sort(all(svv));
                int l = svv.size();

                if(l==1){
                    a[i][j] = 0;
                    continue;
                }
                
                int d = INT_MAX;

                rep(i,1,l){
                    d = min(d,svv[i]-svv[i-1]);
                }

                a[i][j] = d;
            }
        }

        return a;
    }
};

