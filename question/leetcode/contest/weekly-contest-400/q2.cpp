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

// DSU O(alpha(n)) find_set and union_sets
// O(alpha(n)) is approximately O(1) for a reasonable n
struct DSU {
    ll one; // is one index?
    vl p; // parent
    vl s; // size
    ll g; // number of group

    // Constructor
    DSU(ll n, ll o = 1) : one(1), p(n+1), s(n+1, 1), g(n) {
        rep(i, 0, n+1)
            p[i] = i;
    }

    // Find operation
    ll find(ll v) {
        if (v == p[v])
            return v;
        return p[v] = find(p[v]);
    }

    // Same set check
    bool same(ll u, ll v) {
        return find(u) == find(v);
    }

    // Union operation
    void join(ll u, ll v) {
        u = find(u);
        v = find(v);
        if (u != v) {
            if (s[u] < s[v])
                swap(u, v);
            p[v] = u;
            s[u] += s[v];
            g--;
        }
    }
};

// https://cp-algorithms.com/data_structures/segment_tree.html
// segment tree
// O(n) build
// O(log n) find
// O(log n) update

// O(n) in memory
struct ST {
    ll n;
    vl t;

    ST(vl& a): n(a.size()), t(4*n) {
        build(a, 1, 0, n-1);
    }

    ll combine(ll a, ll b){
        return a + b;
        // return max(a,b);
        // return min(a,b);
    }

    void build(vl& a, ll v, ll tl, ll tr){
        if(tl==tr) t[v] = a[tl];
        else {
            ll tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    ll query(ll v, ll tl, ll tr, ll l, ll r){
        if(l>r) return 0;
        // if(l>r) return LONG_LONG_MAX; // for min queries
        if (l==tl and r==tr) return t[v];

        ll tm = (tl+tr)/2;
        return combine(query(v*2, tl, tm, l, min(r,tm)),
            query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    ll query(ll l, ll r){
        return query(1, 0, n-1, l, r);
    }

    void update(ll v, ll tl, ll tr, ll pos, ll new_v){
        if (tl==tr) t[v] = new_v;
        else{
            ll tm = (tl+tr)/2;
            if(pos <= tm) update(v*2, tl, tm, pos, new_v);
            else update(v*2+1, tm+1, tr, pos, new_v);

            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    void update(ll pos, ll new_v){
        update(1, 0, n-1, pos, new_v);
    }
};

class Solution {
public:
    int countDays(int d, vector<vector<int>>& v) {
        ll n = v.size();
        sort(all(v));

        ll a = 0;
        ll last = 1;

        rep(i,0,n){
            // cout << last << v[i][0] << endl;
            if (last < v[i][0]) a+= v[i][0] - last;
            last = max(last, v[i][1]+1LL);
        }

        a += max(0LL, d-(last-1));
        return a;
    }
};