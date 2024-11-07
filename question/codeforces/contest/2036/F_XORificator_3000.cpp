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

// find 0 xor 1 xor 2 xor ... xor n
// O(1) speed
// O(1) space
ll xor_prefix_sum(ll n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;

    assert(1);
}

// find l xor l+1 xor l+2 xor ... xor r
// O(1) speed
// O(1) space
ll xor_range_sum(ll l, ll r){
    if(l==0) return xor_prefix_sum(r);
    return xor_prefix_sum(r) ^ xor_prefix_sum(l-1);
}

void solve(int TC) {
    // ll n;
    // cin >> n;

    ll l,r,i,k;
    cin >> l >> r >> i >> k;

    ll low = l%(1<<i) <= k ? l - l%(1<<i) + k : l - l%(1<<i) + k + (1<<i);
    ll high = r%(1<<i) >= k ? r - r%(1<<i) + k : r - r%(1<<i) - (1<<i) + k;
    if(low>r or high<l){
        cout << xor_range_sum(l,r) << endl;
        return;
    }
    ll n = high/(1<<i) - low/(1<<i) + 1;

    ll higher = high < low ? 0 : (xor_range_sum((low>>i), (high>>i))) << i;
    ll lower = n%2 ? k : 0;

    // cout << (l>>i) << " " << (r>>i) << endl;
    // cout << higher << " " << lower << " " << xor_range_sum(l,r) << endl;
    cout << (xor_range_sum(l,r) ^ (higher+lower)) << endl;
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

