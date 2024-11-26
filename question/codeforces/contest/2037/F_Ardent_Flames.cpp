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

int ok(ll j, vll& v, ll n, ll m, ll k){
    vll ran;

    rep(i,0,n){
        auto [h,p] = v[i];

        ll d = ceild(h,j);
        if(d>m) continue;
        ran.pb({p-(m-d), p+(m-d)});
    }

    sort(all(ran));

    priority_queue<int, vi, greater<int>> q;

    rep(i,0,ran.size()){
        q.push(ran[i].s);

        while(not q.empty() and ran[i].f > q.top()){
            q.pop();
        }

        if(q.size()>=k) return 1;
    }

    return 0;

    // map<ll,ll> map;

    // for(auto [l,r]: ran){
    //     map[l]++;
    //     map[r+1]--;
    // }

    // ll c = 0;

    // for(auto [_,v]: map){
    //     c+=v;
    //     if(c>=k) return 1;
    // }

    // return 0;
}

void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n,m,k;
    cin >> n >> m >> k;

    vll v(n);
    rep(i,0,n){
        cin >> v[i].f;
    }
    rep(i,0,n){
        cin >> v[i].s;
    }

    ll i = 1e9+1;
    ll m_ = 1e9+1;

    ll j = i;

    while(i){
        while(j-i>=1 and ok(j-i, v, n, m, k)) j-=i;
        i/=2;
    }

    if(j==m_){
        cout << -1 << endl;
        return;
    }

    cout << j << endl;
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

