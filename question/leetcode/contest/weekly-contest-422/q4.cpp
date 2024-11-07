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

const int MAX_N = 90;
vector<ll> fact(MAX_N + 1), inv_fact(MAX_N + 1);

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
    int countBalancedPermutations(string s) {

        int n = s.size();
        int t = 0;

        vi v(10);

        rep(i,0,n){
            v[s[i]-'0']++;
            t += s[i]-'0';
        }

        if(t%2) return 0;
        t/=2;
        int n1 = n/2;

        vvl dp(n1+1, vl(t+1));
        dp[0][0] = 1;

        int cs = 0;

        rep(i,0,10){
            int m = v[i];
            cs+=m;
            vvl ndp(n1+1, vl(t+1));

            cout << i << endl;
            rep(j,0,m+1){
                int u1 = j;
                int u2 = m-j;
                
                rep(k,0,n1+1){
                    int t1 = k;
                    int t2 = cs-k;
                    rep(l,0,t+1){
                        if(k-u1>=0 and l-u1*i>=0){
                            ndp[k][l] += ((dp[k-u1][l-u1*i] * C(t1,u1,mod))%mod * C(t2,u2,mod))%mod;
                        }
                        ndp[k][l] %= mod;
                    }
                }
            }

            dp = move(ndp);
        }

        return dp[n1][t];
    }
};

