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

// ll dfs(int p, int i, vvl& dp, int n, vl& v, ll pn){
//     if(dp[p][i] != -1){
//         return dp[p][i];
//     }

//     ll ans = abs(v.back()-pn);

//     rep(j,i,n-1){
//         if(p==0) ans = max(ans, dfs(1-p,j+1,dp,n,v,v[j]));
//         if(p==1) ans = min(ans, dfs(1-p,j+1,dp,n,v,v[j]));
//     }

//     return dp[p][i] = ans;
// }

// void solve(int TC) {
//     // ll n;
//     // cin >> n;

//     int n,a,b;
//     cin >> n >> a >> b;

//     vl v(n);
//     rep(i,0,n) cin >> v[i];

//     vvl dp(2, vl(n,-1));

//     cout << dfs(0,0,dp,n,v,b);
// }

void solve(int TC) {
    /*
    in X first turn, X have 3 choice,
    1. draw all cards, score = |aN - W|,
    2. draw N-1 cards, score = |aN-1 - aN|,
    3. draw k < N-1 cards, then 
        Y can take all cards, score = |aN-ak|, 
        because X is trying the maximize the score, 
        so X will not pick k such that |aN-ak| < choice 1 or 2,
        
        and so Y can only take some cards but not all, and back to X turn, 
        notice that X can always pick until second card and make the score |aN-1 - aN| again,
        so no matter how many card Y take, X can make the minimum score will be |aN-1 - aN| anyway,

        also notice, during Y turn,
        by using the same trick that draw until second last card,
        Y can forbid X to make a move to score better than |aN-1 - aN|, 

        and so the score will end up |aN-1 - aN| again, which is same as choice 2.

    so the answer is the max of 3 choice, which is max(|aN - W|, |aN-1 - aN|)
    */

    int n,a,b;
    cin >> n >> a >> b;

    vi v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    if(n==1) cout << abs(v[n-1]-b);
    else cout << max(abs(v[n-1]-v[n-2]), abs(v[n-1]-b));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve(TC);
    }
}

