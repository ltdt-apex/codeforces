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
    int countBalancedPermutations(string v) {
        precompute_factorials(MAX_N, mod);
        int n = v.size();

        int n1 = ceild(n,2);
        vi count(10);

        int t = 0;
        rep(i,0,n){
            t+=v[i]-'0';
            count[v[i]-'0']++;
        }

        if(t%2==1) return 0;
        t/=2;

        vvl dp(n1+1, vl(t+1));

        dp[0][0] = 1;
        int nn = 0;

        rep(i,0,10){
            // cout << i << endl;
            nn+=count[i];
            vvl ndp(n1+1, vl(t+1));
            rep(j,0,n1+1){
                rep(k,0,t+1){
                    // cout << j << " " << k << endl;
                    if(dp[j][k]==0) continue;
                    rep(l,0,count[i]+1){
                        int nj = j+l;
                        int nk = k+l*i;
                        if(nj>n1 or nk>t) break;
                        int nn2 = nn-nj;
                        int nk2 = count[i]-l;
                        if(nn2<0) continue;
                        // cout << nn2 << " " << nk2 << endl;
                        ndp[nj][nk] += ((dp[j][k] * C(nj, l, mod))%mod * C(nn2, nk2, mod))%mod;
                        ndp[nj][nk]%=mod;
                    }
                }
            }

            // rep(j,0,n1+1){
            //     rep(k,0,t+1){
            //         cout << j << ' ' << k << " " << ndp[j][k] << endl;
            //     }
            // }

            dp = move(ndp);
        }

        // cout << n1 << " " << t << endl;

        return dp[n1][t];
    }
};


// class Solution {
// public:
//     int countBalancedPermutations(string v) {
//         precompute_factorials(MAX_N, mod);
//         int n = v.size();

//         int n1 = ceild(n,2);
//         vi count(10);

//         int t = 0;
//         rep(i,0,n){
//             t+=v[i]-'0';
//             count[v[i]-'0']++;
//         }

//         if(t%2==1) return 0;
//         t/=2;

//         vvvl dp(10, vvl(n+1, vl(t+1, -1)));

//         function<ll(int,int,int,int)> dfs = [&](int i, int j, int k, int c) -> ll{
//             if(i==10){
//                 if(j==n1 and k==t) return 1;
//                 return 0;
//             }

//             if(j>n1 or k>t) return 0;
//             if(dp[i][j][k]!= -1) return dp[i][j][k];

//             ll a = 0;
//             int nc = c+count[i];
//             rep(l,0,count[i]+1){
//                 int nj = j+l;
//                 int nk = k+l*i;
//                 int nn1 = j+l; 
//                 int nk1 = l;
//                 int nn2 = nc-nn1;
//                 int nk2 = count[i]-l;
//                 a+=((dfs(i+1,nj,nk,nc) * C(nn1,nk1,mod))%mod * C(nn2,nk2,mod))%mod;
//                 a%=mod;
//             }

//             return dp[i][j][k] = a;
//         };

//         return dfs(0,0,0,0);
//     }
// };