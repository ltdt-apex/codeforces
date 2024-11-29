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

    int n;
    cin >> n;
    vi v(n);
    vi t(n);

    vector<tuple<double,double,double>> hs;
    hs.pb({0,0,0});

    rep(i,0,n){
        cin >> t[i];
    }
    rep(i,0,n){
        cin >> v[i];
    }

    int cx = 0;

    rep(i,0,n){
        int ch = v[i];
        int ix = t[i];
        hs.pb({cx,cx+ix,ch});
        cx+=ix;
    }

    hs.pb({cx,cx,0});
    double tt = cx;
    double a = 0;
    double ch = 0;

    for(double x=0;x+0.5<=tt;x+=0.5){
        double mh = ch+0.5;
        double nx = x+0.5;
        for(auto [l,r,hh]: hs){
            if(l<=nx and nx<=r){
                mh = min(mh, hh);
            }
            else if(r<=nx){
                mh = min(mh, hh+nx-r);
            }
            else{
                mh = min(mh, hh+l-nx);
            }
        }

        a+=0.5*(mh+ch)/2;
        // cout << nx << ' ' << mh << endl;
        ch = mh;
    }

    cout << setprecision(18) << a << endl;
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

