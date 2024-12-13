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

ll dfs(ll i, vl& dp, vvl& nv, int m, int n){
    if(dp[i] != -1) return dp[i];

    ll a = LONG_LONG_MAX;

    rep(j,0,m){
        if(i & (1<<j)){
            ll k = dfs(i-(1<<j), dp, nv, m, n);
            if(k == LONG_LONG_MAX) continue;
            ll d1 = nv[j][k];
            if(d1 == LONG_LONG_MAX) continue;
            ll d = nv[j][d1];

            a = min(a,d);
        }
    }

    return dp[i] = a;
}

void solve(int TC) {
    ll n;
    cin >> n;

    vl v(n);
    rep(i,0,n){
        int x;
        cin >> x;

        v[i] = x-1;
    }

    ll m = *max_element(all(v))+1;

    vl dp(1<<m, -1);
    dp[0] = 0;
    vvl nv(m, vl(n+1, LONG_LONG_MAX));

    rep(i,0,m){
        ll d = LONG_LONG_MAX;
        repr(j,n,-1){
            nv[i][j] = d;
            if(j-1>=0 and v[j-1] == i) d=j;
        }
    }

    int a = 0;

    rep(i,0,1<<m){
        if(dfs(i,dp,nv,m,n) != LONG_LONG_MAX){
            a = max(a, int(bitset<32>(i).count())*2);
        }
    }

    cout << a << endl;
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

