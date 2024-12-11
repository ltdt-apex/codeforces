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

// https://cp-algorithms.com/data_structures/segment_tree.html
// segment tree
// O(n) build
// O(log n) query
// O(log n) update

// O(n) in memory

enum Type {NORMAL, MAX, MIN};
enum updateType {
    ASSIGNMENT = 1,
    DELTA = 2, 
};
template<typename T>
struct ST {

    vector<T> t;
    int n;
    Type type;

    ST(vector<T>& a, Type type = Type::NORMAL): type(type), n(a.size()) {
        t.assign(4*n, {0,0});
        build(a, 1, 0, n-1);
    }

    void debug(){
        vector<tuple<int, int, int, T>> nodes;
        findNodes(1, 0, n-1, nodes);

        sort(all(nodes), [&](auto a, auto b){
            auto [ai, atl, atr, av] = a;
            auto [bi, btl, btr, bv] = b;

            if(atr-atl == btr-btl){
                return atl < btl;
            }
            else return atr-atl < btr-btl;            
        });

        for(auto [i, tl, tr, v]: nodes){
            cout << i << " " << tl << "-" << tr << " " << v << endl;
        }
    }

    void findNodes(int i, int tl, int tr, vector<tuple<int, int, int, T>>& nodes){
        nodes.pb({i,tl,tr,t[i]});
        if (tl==tr) return;

        int tm = (tl+tr)/2;
        findNodes(i*2, tl, tm, nodes),
        findNodes(i*2+1, tm+1, tr, nodes);
    }

    void build(vector<T>& a, int i, int tl, int tr){
        if(tl==tr) t[i] = a[tl];
        else {
            int tm = (tl+tr)/2;
            build(a, i*2, tl, tm);
            build(a, i*2+1, tm+1, tr);
            t[i] = combine(t[i*2], t[i*2+1]);
        }
    }

    T combine(T a, T b){
        ll c;
        if(a.s == -2){
            c = b.s;
        }
        else if(b.s == -2){
            c = a.s;
        }
        else if(a.s == b.s){
            c = a.s;
        }
        else{
            c = -1;
        }

        return {gcd(a.f, b.f), c};
    }

    T query(int i, int tl, int tr, int l, int r){
        if(l>r) {
            return {0,-2};
        }

        if (l==tl and r==tr) {
            return t[i];
        }

        int tm = (tl+tr)/2;
        // cout << i << " " << tl << " " << tr << ' ' << l << " " << r << endl;
        return combine(
            query(i*2, tl, tm, l, min(r,tm)),
            query(i*2+1, tm+1, tr, max(l,tm+1), r)
        );
    }

    void update(int i, int tl, int tr, int pos, T v, updateType update_type){
        if (tl==tr) {
            if(update_type == ASSIGNMENT) t[i] = v;
            if(update_type == DELTA) t[i] += v;
        }
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm) update(i*2, tl, tm, pos, v, update_type);
            else update(i*2+1, tm+1, tr, pos, v, update_type);

            t[i] = combine(t[i*2], t[i*2+1]);
        }
    }

    T query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    void add(int pos, T delta){
        update(1, 0, n-1, pos, delta, DELTA);
    }

    void update(int pos, T new_v){
        update(1, 0, n-1, pos, new_v, ASSIGNMENT);
    }
};

// ST st(v);
// ST st(v, MIN);
// ST st(v, MAX);
// st.query(l, r);
// st.add(pos, new_v);
// st.update(pos, new_v);

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n, qs;
    cin >> n >> qs;

    vl v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    if (v.size()==1){
        rep(i,0,qs){
            int l, r;
            cin >> l >> r;
            cout << 0 << " ";
        }
        cout << endl;
        return;
    }


    vll d(n-1);

    rep(i,0,n-1){
        d[i] = {abs(v[i]-v[i+1]), abs(v[i]-v[i+1])};
    }

    ST st(d);

    rep(i,0,qs){
        int l, r;
        cin >> l >> r;
        // cout << l << " " << r << endl;

        if(l==r) {
            cout << 0 << " ";
            continue;
        }

        cout << st.query(l-1,r-2).f << " ";
    }

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

