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

ll dfs(ll i, ll j, string& a, string& b, string& c, vvl& dp){
    if(i==-1 and j==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];

    ll ans = 0;
    if(i>0) ans = max(ans, dfs(i-1,j,a,b,c,dp) + int(a[i-1] == c[i+j-1]));
    if(j>0) ans = max(ans, dfs(i,j-1,a,b,c,dp) + int(b[j-1] == c[i+j-1]));

    return dp[i][j] = ans;
}

void solve(int TC) {
    // ll n;
    // cin >> n;

    string a,b,c;
    cin >> a >> b >> c;

    ll n = a.size();
    ll m = b.size();

    vvl dp(n+1, vl(m+1, -1));

    ll ans = dfs(n,m,a,b,c,dp);

    // rep(i,0,n+1){
    //     rep(j,0,m+1){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }cout << endl;

    cout << n+m-ans << endl;
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

