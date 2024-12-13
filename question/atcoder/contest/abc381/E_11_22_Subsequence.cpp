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

void solve(int TC) {
    // ll n;
    // cin >> n;

    ll n, qs;
    cin >> n >> qs;

    string s;
    cin >> s;

    vi p1(n+2);
    vi s2(n+2);
    vi v;

    rep(i,0,n){
        if(s[i]=='/') v.pb(i+1);
        p1[i+1] = p1[i];
        if(s[i]=='1') p1[i+1]++;
    }
    p1[n+1] = p1[n];

    repr(i,n-1,-1){
        s2[i+1] = s2[i+2];
        if(s[i]=='2') s2[i+1]++;
    }
    s2[0] = s2[1];

    int m = v.size();

    rep(_,0,qs){
        int l,r;
        cin >> l >> r;
        // cout << l << " " << r << endl;

        int j = lower_bound(all(v), l) - v.begin();

        if(j==m or v[j]>r){
            cout << 0 << endl;
            continue;
        }


        auto find = [&](int i){
            // cout << i << endl;
            int c1 = p1[v[i]] - p1[l-1];
            int c2 = s2[v[i]] - s2[r+1];

            return mp(c1,c2);
        };

        // cout << j << " " << k << endl;

        int a = 0;

        int k = v.size();
        while(k){
            while(j+k<m and v[j+k]<=r and find(j+k).f<=find(j+k).s) j+=k;
            k/=2;
        }

        // cout << j << endl;

        a = max(a, min(find(j).f, find(j).s)*2+1);

        if(j+1<m and v[j+1]<=r){
            a = max(a, min(find(j+1).f, find(j+1).s)*2+1);
        }

        cout << a << endl;
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

