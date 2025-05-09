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

const int MAX_N = 90;
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


class Solution {
    public:
        int magicalSum(int m, int s, vector<int>& v) {
            /*
            let say v have size n = [1,2,3,4,5]
            for m=3, s=2, n=5
            seq can be [0,0,2] the array product is C(2,2) * v[0]**2 * C(3,1) * v[2] ** 1
            seq can also be [0,2,2] the array product is C(1,1) * v[0]**1 * C(3,2) * v[2] ** 2

            we can see that we can split the problem into subproblem using dp,
            for example, [0,0,2], mean 
                we choose index 0 -> 2 times, 
                    now we have val = 1+1 = 2(10), 
                    and current array product is C(2,2) * v[0]**2
                we choose index 1 -> 0 times, 
                we choose index 2 -> 1 times, 
                    now we have val = 2(10) + 2**2(100) = (110), 
                    and current array product is C(2,2) * v[0]**2 * C(3,1) * v[2] ** 1

            so we can see that we can build the final answer by looping each index using dp,
    
            for l=0...n, we find the possible product using first l bits
            for each l
                dp[i][j][k] mean current array product with 
                    i = current value (value that can carry to future bit), 
                    j = remaining index that can use
                    k = remaining set bits need to fulfill.

            remaining work are just math.
            */
            precompute_factorials(MAX_N, mod);
            int n = v.size();

            vvvl dp(m+1, vvl(m+1, vl(s+1)));

            dp[0][m][s] = 1;

            rep(l,0,n){
                vvvl ndp(m+1, vvl(m+1, vl(s+1)));
                rep(i,0,m+1){
                    rep(j,0,m+1){
                        rep(k,0,s+1){
                            // can speed up by a lot
                            if(dp[i][j][k]==0) continue;
                            rep(u,0,j+1){
                                int ni = i>>1;
                                ni+=u;
                                int iss = ni&1;
                                int nj = j-u;
                                int nk = k-iss;
                                int nc = m-nj;
                                
                                if(ni>m) break;
                                if(nk<0) continue;

                                ll t = C(nc, u, mod);
                                t*=dp[i][j][k];
                                t%=mod;
                                t*=bin_pow(v[l],u,mod);
                                t%=mod; 
                                
                                // cout << d << " " << j-u << ' ' << k-iss << endl;
                                ndp[ni][nj][nk]+=t;
                                ndp[ni][nj][nk]%=mod;
                            }
                        }
                    }
                }

                dp = move(ndp);
                // rep(i,0,m+1){
                //     rep(j,0,m+1){
                //         rep(k,0,s+1){
                //             cout << i << ' ' << j << " " << k << " " << dp[i][j][k] << endl;
                //         }
                //     }
                // }
            }

            ll a = 0;

            rep(i,0,m+1){
                int k = i>>1;
                int c = 0;
                while(k){
                    c+=k%2;
                    k/=2;
                }

                if(c>s) continue;

                // cout << i << ' ' << c << endl;
                a+=dp[i][0][c];
                a%=mod;
            }

            return a;
        }
    };
