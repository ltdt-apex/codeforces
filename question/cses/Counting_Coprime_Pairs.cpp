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

vvl find_pf(ll n, vl& soe){
    vvl pf(n+1);

    rep(i,2,n+1){
        ll x = i;
        while(x!=1){
            ll d = soe[x];
            pf[i].pb(d);
            while(x%d==0) x/=d;
        }
    }

    return pf;
}

void find_sfds(ll i, vl& pf, vll& sfd, int t, ll cur){
    if(i==pf.size()){
        if(t==0) return;
        sfd.pb({cur, t});
        return;
    }

    cur*=pf[i];
    find_sfds(i+1,pf,sfd,t+1,cur);
    cur/=pf[i];
    find_sfds(i+1,pf,sfd,t,cur);
}

ll find_number_of_coprime(vl& v){
    ll n = v.size();

    ll m = *max_element(all(v));

    vl soe = find_soe(m);
    vvl pf = find_pf(m, soe);
    vl count(m+1);

    ll a = 0;

    rep(i,0,n){
        ll x = v[i];
        ll total = 0;

        vll sfds;
        find_sfds(0,pf[x],sfds,0,1);

        for(auto [sfd, up]: sfds){
            if(up%2){
                total += count[sfd];
                count[sfd]++;
            }
            else{
                total -= count[sfd];
                count[sfd]++;
            }
        }

        a+=i-total;
    }

    return a;
}


void solve(int TC) {
    // ll n;
    // cin >> n;

    int n; cin >> n;

    vl v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    cout << find_number_of_coprime(v) << endl;
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

