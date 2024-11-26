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

const ll mod = 998244353;

vl pre(ll n){
    vl p(n+1, 1);
    for(ll i=2;i<n+1;i++){
        if(p[i]!=1) continue;

        for(ll j=i;j<n+1;j+=i) p[j] = i;
    }

    return p;
}

void dfs(int i, vl& pf, vll& r, int t, ll cur){
    if(i==pf.size()){
        if(t==0) return;
        r.pb({cur, t});
        return;
    }

    cur*=pf[i];
    dfs(i+1,pf,r,t+1,cur);
    cur/=pf[i];
    dfs(i+1,pf,r,t,cur);
}

void solve(int TC) {
    // ll n;
    // cin >> n;


    ll n;
    cin >> n;

    vl v(n);

    rep(i,0,n){
        cin >> v[i];
    }

    ll m = *max_element(all(v));
    vl p = pre(m);

    // rep(i,1,10){
    //     cout << i << " " << p[i] << endl;
    // }

    vl dp(m+1);

    rep(i,0,n){
        // cout << i << endl;
        ll x = v[i];
        vl pf;

        while(x!=1){
            ll d = p[x];
            pf.pb(d);
            while(x%d==0) x/=d;
        }

        vll comb;
        dfs(0,pf,comb,0,1);

        // for(auto p: pf){
        //     cout << "p: " << p << " " << endl;
        // }

        // for(auto [val, o]: comb){
        //     cout << val << " " << o << endl;
        // }

        if(i==0){
            for(auto [val, o]: comb){
                dp[val] = 1;
            }
        }
        else{
            ll total = 0;
            for(auto [val, o]: comb){
                if(o%2){
                    total+=dp[val];
                    total%=mod;
                }
                else{
                    total-=dp[val];
                    total+=mod;
                    total%=mod;
                }
            }
            if(i==n-1){
                cout << total << endl;
                return;
            }

            for(auto [val, o]: comb){
                dp[val]+=total;
                dp[val]%=mod;
            }
        }
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

