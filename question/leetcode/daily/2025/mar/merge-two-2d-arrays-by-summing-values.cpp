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
        vector<vector<int>> mergeArrays(vector<vector<int>>& v1, vector<vector<int>>& v2) {
            int n = v1.size();
            int m = v2.size();
            
            int i = 0;
            int j = 0;
            vvi a;

            while(i<n and j<m){
                if(v1[i][0] == v2[j][0]){
                    a.pb({v1[i][0], v1[i][1]+v2[j][1]});
                    i++;
                    j++;
                }
                else if(v1[i][0] < v2[j][0]){
                    a.pb(v1[i]);
                    i++;
                }
                else {
                    a.pb(v2[j]);
                    j++;
                }
            }

            while(i<n){
                a.pb(v1[i]);
                i++;
            }
            while(j<m){
                a.pb(v2[j]);
                j++;
            }

            return a;
        }
    };
