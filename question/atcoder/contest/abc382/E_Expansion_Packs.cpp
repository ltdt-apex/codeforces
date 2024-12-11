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

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n,m;
    cin >> n >> m;

    vector<double> v(n);
    rep(i,0,n){
        double x;
        cin >> x;
        v[i] = x/100;
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1));
    dp[0][0] = 1;

    rep(i,1,n+1){
        rep(j,0,n+1){
            dp[i][j] = dp[i-1][j]*(1-v[i-1]);
            if(j>0) dp[i][j] += dp[i-1][j-1]*v[i-1];
            // cout << dp[i][j] << endl;
        }
    }

    vector<double> e(m+1, 0);

    rep(i,1,m+1){
        double x = 1;
        rep(j,1,n+1){
            x+=e[max(i-j,(ll)0)] * dp[n][j];
        }
        x/=(1-dp[n][0]);
        e[i] = x;
    }

    cout << setprecision(18) << e[m];
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

