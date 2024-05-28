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
#define ceild(a,b) (a)%(b) ? ((a)/(b) + 1) : (a)/(b)
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
 
const ll mod = 1e9 + 7;
 
const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;
 
const int lt = 32;

bool isNumeric(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (...) {
        return false;
    }
}
 
// dsu O(alpha(n)) find_set and union_sets
// O(alpha(n)) is approximately O(1) for a reasonable n
pair<vl,vl> init_set(ll n){
    vl parent(n);
    rep(i,0,n){
        parent[i] = i;
    }
    vl size(n, 1);
 
    return {parent, size};
}
 
void make_set(ll v, vl& parent, vl& size) {
    parent[v] = v;
    size[v] = 1;
}
 
ll find_set(ll v, vl& parent) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v], parent);
}
 
ll same_set(ll u, ll v, vl& parent){
    return find_set(u, parent) == find_set(v, parent);
}
 
void union_sets(ll a, ll b, vl& parent, vl& size) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
 
void solve(int TC) {
    ll n,m;
    cin >> n >> m;
    if(!n and !m){
        exit(0);
    }

    vll pos;
    pos.pb({0,0});
    rep(i,0,n){
        ll x,y;
        cin >> x >> y;
        pos.pb({x,y});
    }

    vector<vector<double>> d(n+1, vector<double>(n+1, 1e9));
    rep(i,1,n+1){
        d[i][i] = 0;
    }
    rep(i,0,m){
        ll u,v;
        cin >> u >> v;

        d[u][v] = sqrt(pow(pos[u].f - pos[v].f, 2) + pow(pos[u].s - pos[v].s, 2));
        d[v][u] = d[u][v];
        // cout << d[u][v] << endl;
    }

    rep(k,1,n+1){
        rep(i,1,n+1){
            rep(j,1,n+1){
                if(d[i][k]!= 1e9 and d[k][j]!=1e9){
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }

    double c = 0;
    ll fu, fv;

    rep(i,1,n+1){
        rep(j,1,n+1){
            // cout << i << " " << j << endl;
            double nd = sqrt(pow(pos[i].f - pos[j].f, 2) + pow(pos[i].s - pos[j].s, 2));
            double total = 0;
            
            rep(k,1,n+1){
                rep(l,1,n+1){
                    total += d[k][l] - min(d[k][l], min(d[k][i] + nd + d[j][l], d[k][j] + nd + d[j][l]));
                }
            }

            // cout << total << endl;
            if (c < total-1e-9){
                c = total;
                fu = i;
                fv = j;
            }
        }
    }

    // cout << c << endl;

    if(c < 1.0){
        cout << "No road required" << endl;
    }else{
        cout << fu << " " << fv << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int TC = 1;
    // cin >> TC;
    while (1) solve(TC);
}