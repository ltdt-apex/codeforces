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

const int MAX_N = pow(10,4)+30;
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

vl find_soe(ll n){
    vl soe(n+1, 1);

    for(ll i=2;i<=n;i++){
        if(soe[i]!=1) continue;

        for(ll j=i;j<=n;j+=i){
            soe[j] = i;
        }
    }

    return soe;
}


class Solution {
public:
    int idealArrays(int n, int m) {
            /*
            we can answer the problem by answering the sum of number of ideal array 
            that end with i=1...m.

            assume n=3,
            let's say we want to find number of ideal array that end with 12,
            since 12 = 2*2*3,
            we are essentially finding the number of ways to put each 2,2,3 into any of 3 holes,
            e.g. if we put all the numbers 2,2,3 into 1st hole, 
            we can form ideal array [12,12,12].
            e.g. if we put all the numbers 2,3 into 2nd hole and another 2 into 3rd hole,
            we can form ideal array [1,6,12].

            to find the number of ways to put each 2,2,3 into any of 3 holes,
            we split to case per unique prime, i.e. we handle all 2s first,
            we have two 2s prime for 12,
            say k=no. of primes of 2, in our case, k=2,
            we need to assign two 2s into 3 holes, 
            e.g. 2 | 2 | (empty)
            e.g. 2,2 | (empty) | (empty)
            e.g. 2 | (empty) | 2

            the way to assign is just classic stars and bars problem, 
            we have k star and n-1 bar, we want to find the ways to sep stars,
            from n-1+k elements, we choose n-1 to be bars, or k to be the stars,
            C(n-1+k, k), so in our case is C(4,2)
            */
            precompute_factorials(MAX_N, mod);

            ll ans = 0;
            vl soe = find_soe(m);
            rep(i,1,m+1){
                int x = i;
                vi ps;
                while(x>1){
                    int p = soe[x];
                    int c = 0;
                    while(x%p==0){
                        x/=p;
                        c++;
                    }
                    ps.pb(c);
                }

                ll a = 1;
                for(auto k: ps){
                    int nn = n-1+k;
                    a*=C(nn,n-1,mod);
                    a%=mod;
                }

                // cout << i << " " << a << endl;

                ans+=a;
                ans%=mod;
            }

            return ans;
        }
    };