#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll,ll>> vll;
typedef vector<vector<pair<ll,ll>>> vvll;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<tuple<ll, ll, ll>> vlll;
 
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
 
void solve(ll n, ll m) {
    vlll e;
    rep(i,0,m){
        ll u,v,w;
        cin >> u >> v >> w;

        e.pb({u,v,w});
        e.pb({v,u,-w});
    }

    vl d(n+1, LONG_LONG_MAX);
    d[1] = 0;

    int x;
    rep(i,0,n){
        x = 0;
        for(auto [u,v,w]: e){
            if(d[u] != LONG_LONG_MAX and d[u]+w < d[v]){
                d[v] = d[u] + w;
                x = 1;
            }
        }
    }

    if(x)
        cout << "Y" << endl;
    else
        cout << "N" <<endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    while(1){
        ll n,m;
        cin >> n >> m;

        if(!n and !m){
            return 0;
        }

        solve(n,m);
    }
}