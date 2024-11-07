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

const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;

const int lt = 32;

// https://cp-algorithms.com/algebra/binary-exp.html
// binary exponentiation
// O(log m) speed
// O(1) in memory
// find mod n**m in O(log m) speed

ll bin_pow(ll n, ll m, ll mod){
    ll a = 1;

    while(m){
        if(m%2) a = n*a%mod;
        n=n*n%mod;
        m/=2;
    }

    return a;
}

class Solution {
public:
    vector<int> getFinalState(vector<int>& v, int k, int m) {
        // iteratively multiply after at most log(10**9) (when m > 2) step 
        // until smallest number * m > biggest number,
        // then we can averagely distribute remaining steps into all v 
        // because the remaining steps in circular
        if(m==1) return v;
        ll n = v.size();
        
        set<pll> s;

        rep(i,0,n){
            s.insert({v[i],i});
        }

        while(k){
            auto [v1,i] = *s.begin();
            auto [v2,j] = *s.rbegin();
            if(v1*m>v2) break;

            s.erase({v1,i});
            v1*=m;
            s.insert({v1,i});

            k--;
        }

        vi a(n);

        ll d = k/n;
        ll r = k%n;
        ll c = 0;

        for(auto [v,i]: s){
            ll p = d + (c<r);
            a[i] = (v*bin_pow(m,p,mod))%mod;
            c++;
        }

        return a;
    }
};