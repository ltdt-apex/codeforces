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

vvl dfs(vvii& adj, int start, int n, set<int>& hs){
    set<tuple<ll, ll, ll>> s;
    s.insert({0,start,0});
    vvl ans(n+1, vl(2,LONG_LONG_MAX));
    ans[start][0] = 0;

    while(!s.empty()){
        auto [d,u,h] = *s.begin();
        s.erase(s.begin());

        if(hs.count(u)) h = 1;

        for(auto [v,w]: adj[u]){
            ll nd = d;
            if(h) nd+=w/2;
            else nd+=w;

            if(nd < ans[v][h]){
                s.erase({ans[v][h],v,h});
                ans[v][h] = nd;
                s.insert({nd,v,h});
            }
        }
    }

    return ans;
}

void solve(int TC) {
    int n,m,h;
    cin >> n >> m >> h;

    set<int> hs;

    rep(i,0,h){
        int x;
        cin >> x;
        hs.insert(x);
    }

    vvii adj(n+1);
    rep(i,0,m){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].pb({v,w});
        adj[v].pb({u,w});
    }

    vvl s = dfs(adj,1,n,hs);
    vvl e = dfs(adj,n,n,hs);

    ll ans = LONG_LONG_MAX;
    rep(i,1,n+1){
        // cout << s[i][0] << " " << s[i][1] << " " << e[i][0] << " " << e[i][1] << endl;
        ans = min(ans, max(min(s[i][0], s[i][1]), min(e[i][0], e[i][1])));
    }

    ans == LONG_LONG_MAX ? cout << -1 << endl: cout << ans << endl;
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

