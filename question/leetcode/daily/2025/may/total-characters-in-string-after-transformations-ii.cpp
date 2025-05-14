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

// https://github.com/ShahjalalShohag/code-library/blob/main/Math/Matrix%20Exponentiation.cpp
// matrix exponentiation
// O(d^3 log(m)) for pow function, which d = matrix size, m = power

// O(d^2) in memory
struct Mat {
    ll n, m;
    vector<vector<ll>> v;

    Mat() {}
    Mat(ll _n, ll _m) {n = _n; m = _m; v.assign(n, vl(m, 0)); }
    Mat(vvl _v) { n = _v.size(); m = n ? _v[0].size() : 0; v = _v; }

    inline void make_id() {
        assert(n == m);

        rep(i,0,n){
            v[i][i] = 1;
        }
    }
    inline Mat operator + (const Mat &b) {
        assert(n == b.n && m == b.m);

        Mat ans = Mat(n, m);

        rep(i,0,n) {
            rep(j,0,m) {
                ans.v[i][j] = (v[i][j] + b.v[i][j]) % mod;
            }
        }

        return ans;
    } 
    inline Mat operator - (const Mat &b) {
        assert(n == b.n && m == b.m);

        Mat ans = Mat(n, m);

        rep(i,0,n) {
            rep(j,0,m) {
                ans.v[i][j] = (v[i][j] - b.v[i][j] + mod) % mod;
            }
        }

        return ans;
    }
    inline Mat operator * (const Mat &b) {
        assert(m == b.n);

        Mat ans = Mat(n, b.m);

        rep(i,0,n) {
            rep(j,0,m){
                rep(k,0,b.m){
                    ans.v[i][k] += v[i][j]*b.v[j][k];
                    ans.v[i][k]%=mod;
                }
            }
        }

        return ans;
    }
    inline Mat pow(ll k) {
        assert(n == m);

        Mat ans(n, n), t=v;
        ans.make_id();

        while (k) {
            if (k & 1) ans = t*ans;
            t = t*t;
            k >>= 1;
        }

        return ans;
    }
    inline Mat& operator += (const Mat& b) { return *this = (*this) + b; }
    inline Mat& operator -= (const Mat& b) { return *this = (*this) - b; }
    inline Mat& operator *= (const Mat& b) { return *this = (*this) * b; }
    inline bool operator == (const Mat& b) { return v == b.v; }
    inline bool operator != (const Mat& b) { return v != b.v; }
};

class Solution {
    public:
        int lengthAfterTransformations(string s, int t, vector<int>& v) {
            vvl m(26, vl(26));

            rep(i,0,26){
                rep(j,0,v[i]){
                    m[(j+i+1)%26][i] = 1;
                }
            }

            Mat M(m);

            Mat dp = M.pow(t);

            vvl x(26, vl(1));

            for(auto c: s){
                x[c-'a'][0]++;
            }
            Mat X(x);

            dp*=X;

            ll a = 0;
            rep(i,0,26){
                a+=dp.v[i][0];
                a%=mod;
            }

            return a;
        }
    };