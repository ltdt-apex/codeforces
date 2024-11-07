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

// https://cp-algorithms.com/algebra/binary-exp.html
// binary exponentiation
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

void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n,k;
    cin >> n >> k;

    vl v(n+1);
    rep(i,1,n+1){
        int u;
        cin >> u;

        v[i] = u;
    }

    vvl gs;
    set<int> s;
    rep(i,1,n+1){
        if(not s.count(i)){
            vl g;
            int c = i;
            while(not s.count(c)){
                g.pb(c);
                s.insert(c);
                c=v[c];
            }
            gs.pb(g);
        }
    }

    int m = gs.size();
    unordered_map<int, pair<int,int>> map;

    rep(i,0,m){
        rep(j,0,gs[i].size()){
            map[gs[i][j]] = {i,j};
        }
    }

    rep(i,1,n+1){
        auto [si, sj] = map[i];
        ll s = gs[si].size();
        ll r = bin_pow(2,k,s);

        sj = (sj+r)%s;

        cout << gs[si][sj] << " ";
    }
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

