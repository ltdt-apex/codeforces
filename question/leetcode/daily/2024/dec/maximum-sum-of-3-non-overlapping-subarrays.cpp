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
    vector<int> maxSumOfThreeSubarrays(vector<int>& v, int k) {
        int n = v.size();

        vl p(n);
        vl p2(n);
        vl p3(n);
        vl par1(n);
        vl par2(n);
        ll c = 0;
        vi a;

        rep(r,0,n){
            c+=v[r];
            if(r-k+1>=0) {
                p[r-k+1] = c;
                c-=v[r-k+1];
            }
        }
        // rep(i,0,n){
        //     cout << p[i] << " ";
        // }cout << endl;


        c = -LONG_LONG_MAX;
        int j = 0;

        rep(r,0,n){
            if(r-k>=0) {
                if(p[r-k]>c){
                    c = p[r-k];
                    j = r-k;
                }
                par1[r] = j;
                p2[r] = c+p[r];
            }
        }

        // rep(i,0,n){
        //     cout << p2[i] << " ";
        // }cout << endl;

        c = -LONG_LONG_MAX;
        j=0;
        rep(r,0,n){
            if(r-k>=0) {
                if(p2[r-k]>c){
                    c = p2[r-k];
                    j=r-k;
                }
                par2[r] = j;
                p3[r] = c+p[r];
            }
        }

        // rep(i,0,n){
        //     cout << p3[i] << " ";
        // }cout << endl;

        ll b = -LONG_LONG_MAX;

        rep(i,0,n){
            if(b<p3[i]){
                a = {(int)par1[par2[i]],(int)par2[i],(int)i};
                b = p3[i];
            }
        }

        return a;
    }
};