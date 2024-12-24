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

// https://cp-algorithms.com/string/z-function.html
// The Z-function for the string is an array z of length n where the 
// i-th element is equal to the greatest number of characters 
// starting from the position i that coincide with the first characters of s
// i.e. if z[i] = j, this means j is longest option that s[0...j-1] == v[i...i+j-1]

// O(n) in speed, which bruteforce is O(n^2), or even O(n^3)
// O(n) in memory

vector<int> zfunction(vi s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

class Solution {
public:
    int beautifulSplits(vector<int>& v) {
        int n = v.size();
        // vvi dp2(n, vi(n));

        vi zp = zfunction(v);

        // rep(i,0,n){
        //     vi pre;
        //     rep(j,n-i-1,n){
        //         pre.pb(v[j]);
        //     }
        //     pre.pb(-1);
        //     rep(j,0,n){
        //         pre.pb(v[j]);
        //     }

        //     vi z = zfunction(pre);

        //     rep(j,0,n){
        //         dp2[i][j] = z[j+i+2];
        //     }
        // }

        int a = 0;

        rep(le,0,n){
            vi pre;
            rep(j,le+1,n){
                pre.pb(v[j]);
            }
            vi z = zfunction(pre);
            rep(rs,le+2,n){
                // cout << le << " " << rs << endl;
                int s1 = le+1;
                int s2 = rs-le-1;
                int s3 = n-rs;


                // cout << (s1<=s2 and dp1[s1-1][s1*2-1]==s1) << " " << (s2<=s3 and dp2[s3-1][s1+s2-1]==s2) << endl;
                // if((s1<=s2 and zp[s1]>=s1) or (s2<=s3 and dp2[s3-1][s1]>=s2)){
                if((s1<=s2 and zp[s1]>=s1) or (s2<=s3 and z[s2]>=s2)){
                    a++;
                }
            }
        }

        return a;
    }
};