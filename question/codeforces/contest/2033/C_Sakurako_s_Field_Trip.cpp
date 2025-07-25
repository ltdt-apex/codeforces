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

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n;
    cin >> n;
    vl v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    ll m = ceild(n,2);

    vvl dp(m, vl(2,0));

    rep(i,1,m){ 
        dp[i][0] = min(dp[i-1][0] + !!(v[i] == v[i-1])+ !!(v[n-i-1] == v[n-i]), dp[i-1][1] + !!(v[i] == v[n-i])+ !!(v[n-i-1] == v[i-1]));
        dp[i][1] = min(dp[i-1][0] + !!(v[n-i-1] == v[i-1])+ !!(v[i] == v[n-i]), dp[i-1][1] + !!(v[n-i-1] == v[n-i])+ !!(v[i] == v[i-1]));

        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }

    int a = 0;
    if(n%2==0){
        a+=(v[n/2] == v[n/2-1]);
    }

    cout << min(dp[m-1][0], dp[m-1][1]) + a << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    cin >> TC;
    while (TC--) {
        solve(TC);
    }
}

