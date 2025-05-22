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
#define range(i,b) for (int i = 0; i < b; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repr(i,a,b) for (int i = a; i > b; i--)
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

    ll n,m,l;
    cin >> n >> m >> l;

    vi v1;
    vi v2;
    rep(i,0,l){
        int x;
        cin >> x;
        if(x%2) v1.pb(x);
        else v2.pb(x);
    }

    sort(rall(v1));
    sort(rall(v2));

    ll m1 = 0;
    ll m2 = 0;
    int n1 = v1.size();
    int n2 = v2.size();

    if(n1>0){
        rep(i,0,n2){
            m1+=v2[i];
        }
        rep(i,0,n1-(n1%2==0)){
            m1+=v1[i];
        }
    }
    rep(i,0,n2){
        m2+=v2[i];
    }
    rep(i,0,n1-n1%2==1){
        m2+=v1[i];
    }

    vvi adj(n+1);
    rep(i,0,m){
        int u,v;
        cin >> u >> v;

        adj[u].pb(v);
        adj[v].pb(u);
    }
    

    vvi dis(n+1, {INT_MAX, INT_MAX});

    queue<pii> q;
    q.push({1,0});

    while(not q.empty()){
        auto [u,d] = q.front(); q.pop();
        dis[u][1-d%2] = d;

        for(auto v: adj[u]){
            int nd = d+1;
            if(dis[v][1-nd%2] < nd) continue;

            q.push({v,nd});
        }
    }

    rep(i,1,n+1){
        // cout << dis[i][0] << ' ' << dis[i][1] << endl;
        if(dis[i][0]<=m1 or dis[i][1]<=m2){
            cout << "1";
        }
        else{
            cout << "0";
        }
    }

    // cout << "ok" << endl;

    cout << endl;
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

