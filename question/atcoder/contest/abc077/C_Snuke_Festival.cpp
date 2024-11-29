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

    vi v1(n);
    vi v2(n);
    vi v3(n);

    rep(i,0,n){
        cin >> v1[i];
    }
    rep(i,0,n){
        cin >> v2[i];
    }
    rep(i,0,n){
        cin >> v3[i];
    }

    sort(all(v1));
    sort(all(v2));
    sort(all(v3));

    // rep(i,0,n){
    //     cout << v1[i] << " ";
    // }cout << endl;
    // rep(i,0,n){
    //     cout << v2[i] << " ";
    // }cout << endl;
    // rep(i,0,n){
    //     cout << v3[i] << " ";
    // }cout << endl;

    ll i = -1;
    ll k = -1;
    ll a = 0;

    rep(j,0,n){
        while(k+1<v3.size() and v3[k+1]<=v2[j]){
            k++;
        }
        while(i+1<v1.size() and v1[i+1]<v2[j]){
            i++;
        }

        a+= (i+1)*(n-1-k);
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

