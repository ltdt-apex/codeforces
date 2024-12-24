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

const int MAX_N = 1000;
vl fact(MAX_N + 1), inv_fact(MAX_N + 1);

// copy from binary exponentiation
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

void precompute_factorials(int max_n, int mod) {
    fact[0] = 1;
    for (int i = 1; i <= max_n; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv_fact[max_n] = bin_pow(fact[max_n], mod - 2, mod); // Fermat's theorem

    for (int i = max_n - 1; i >= 0; i--) {
        inv_fact[i] = inv_fact[i + 1] * (i + 1) % mod;
    }
}

ll C(int n, int k, int mod) {
    if (k > n || k < 0) return 0;
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

// precompute_factorials(MAX_N, mod);


class Solution {
public:
    int countKReducibleNumbers(string s, int k) {
        precompute_factorials(MAX_N, mod);
        
        int n = s.size();
        vl dp(n+1);

        rep(i,2,n+1){
            dp[i] = dp[bitset<32>(i).count()]+1;
        }


        ll c1 = 0;
        vl bits(n+1,0);

        rep(i,0,n){
            if(s[i]=='1'){
                rep(c2,0,n-i){
                    if(c1+c2>0){
                        bits[c1+c2] += C(n-i-1, c2, mod);
                        bits[c1+c2]%=mod;
                    }
                }
                c1++;
            }
        }


        ll a = 0;
        rep(i,0,n+1){
            if(dp[i]+1<=k){
                a+=bits[i];
                a%=mod;
            }
        }

        return a;
    }
};
