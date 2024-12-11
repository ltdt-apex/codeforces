#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

typedef pair<int, int> pii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<tuple<int, int, int>> viii;
typedef vector<tuple<int, int, int, int>> viiii;

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

// https://cp-algorithms.com/data_structures/segment_tree.html
// segment tree(ranged update version)
// adding/assignment on segments, query for max, min, sum
// O(n) build
// O(log n) query
// O(log n) update

// O(n) in memory

enum Type {NORMAL, MAX, MIN};
enum updateType {
    NONE = 0, 
    ASSIGNMENT = 1,
    DELTA = 2, 
};
template<typename T>
struct ST {
    Type type;
    int n;
    vector<T> t;
    vector<T> lazy_set;
    vector<T> marked; // for checking if lazy_set is made?
    vector<T> lazy_add;

    ST(vector<T>& a, Type type = Type::NORMAL): type(type), n(a.size()), t(4*n), lazy_set(4*n, 0), marked(4*n, 0), lazy_add(4*n, 0) {
        build(a, 1, 0, n-1);
    }

    void debug(){
        vector<tuple<int, int, int, T, T, T>> nodes;
        findNodes(1, 0, n-1, nodes);

        sort(all(nodes), [&](auto a, auto b){
            auto [ai, atl, atr, av, alazy_set, alazy_add] = a;
            auto [bi, btl, btr, bv, blazy_set, blazy_add] = b;

            if(atr-atl == btr-btl){
                return atl < btl;
            }
            else return atr-atl < btr-btl;
        });

        for(auto [i, tl, tr, v, lazy_set, lazy_add]: nodes){
            cout << i << " " << tl << "-" << tr << " " << v << " " << lazy_set << " " << lazy_add << endl;
        }
    }

    void findNodes(int i, int tl, int tr, vector<tuple<int, int, int, T, T, T>>& nodes){
        nodes.pb({i,tl,tr,t[i],lazy_set[i], lazy_add[i]});
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
        if(type == Type::NORMAL) return a + b;
        if(type == Type::MAX) return max(a,b);
        if(type == Type::MIN) return min(a,b);

        assert(false);
    }

    T default_outbound_return(){
        if (type == Type::NORMAL) return 0;
        if (type == Type::MAX) return -numeric_limits<T>::max();
        if (type == Type::MIN) return numeric_limits<T>::max();

        assert(false);
    }

    void update_lazy(T& a, T b, updateType update_type){
        if(update_type == ASSIGNMENT) a=b;
        if(update_type == DELTA) a+=b;
    }

    void push(int i, int tl, int tr){
        int tm = (tl+tr)/2;
        int l = tm-tl+1;
        int r = tr-tm;

        if(marked[i] == 1){
            if(type == NORMAL){
                T lazyl = lazy_set[i] * l;
                T lazyr = lazy_set[i] * r;
                update_lazy(t[i*2], lazyl, ASSIGNMENT);
                update_lazy(t[i*2+1], lazyr, ASSIGNMENT);
            }
            if(type == MAX or type == MIN){
                update_lazy(t[i*2], lazy_set[i], ASSIGNMENT);
                update_lazy(t[i*2+1], lazy_set[i], ASSIGNMENT);
            }
            
            lazy_set[i*2] = lazy_set[i*2+1] = lazy_set[i];
            marked[i*2] = marked[i*2+1] = marked[i];
            marked[i] = 0;
        }

        if(type == NORMAL){
            T lazyl = lazy_add[i] * l;
            T lazyr = lazy_add[i] * r;
            update_lazy(t[i*2], lazyl, DELTA);
            update_lazy(t[i*2+1], lazyr, DELTA);
        }
        if(type == MAX or type == MIN){
            update_lazy(t[i*2], lazy_add[i], DELTA);
            update_lazy(t[i*2+1], lazy_add[i], DELTA);
        }

        lazy_add[i*2] += lazy_add[i];
        lazy_add[i*2+1] += lazy_add[i];
        lazy_add[i] = 0;
    }

    void default_update(int i, T v, int tl, int tr, updateType update_type){
        if(type == NORMAL) update_lazy(t[i], v*(tr-tl+1), update_type);
        if(type == MAX or type == MIN) update_lazy(t[i], v, update_type);

        if(update_type == ASSIGNMENT){
            marked[i] = 1;
            lazy_set[i] = v;
            lazy_add[i] = 0;
        }
        if(update_type == DELTA){
            lazy_add[i] += v;
        }
    }

    T query(int i, int tl, int tr, int l, int r){
        if(l>r) {
            return default_outbound_return();
        }

        if (l==tl and r==tr) {
            return t[i];
        }

        push(i, tl, tr);

        int tm = (tl+tr)/2;
        return combine(
            query(i*2, tl, tm, l, min(r,tm)),
            query(i*2+1, tm+1, tr, max(l,tm+1), r)
        );
    }

    void update(int i, int tl, int tr, int l, int r, T v, updateType update_type){
        if(l>r) return;

        if (l==tl and r==tr) {
            default_update(i, v, tl, tr, update_type);
        }
        else{
            push(i, tl, tr);
            int tm = (tl+tr)/2;
            update(i*2, tl, tm, l, min(r,tm), v, update_type);
            update(i*2+1, tm+1, tr, max(l,tm+1), r, v, update_type);

            t[i] = combine(t[i*2], t[i*2+1]);
        }
    }

    T query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    void range_add(int l, int r, T delta){
        update(1, 0, n-1, l, r, delta, DELTA);
    }

    void update(int l, int r, T new_v){
        update(1, 0, n-1, l, r, new_v, ASSIGNMENT);
    }
};

// ST st(v);
// ST st(v, MIN);
// ST st(v, MAX);
// st.query(l, r);
// st.update(l, r, new_v);
// st.range_add(l, r, delta);

void solve(int TC) {
    // ll n;
    // cin >> n;

    int n,m,k;
    cin >> n >> m >> k;

    vi a(k);
    vi c(m, n);

    ST st = ST(c, MIN);

    viiii v(k);
    rep(i,0,k){
        int r,c,l;
        cin >> r >> c >> l;

        v[i] = {r-1,c-1,c+l-2,i};
    }

    sort(rall(v));

    rep(i,0,k){
        auto [r,cl,cr,j] = v[i];
        // cout << r << " " << cl << " " << cr << " " << j << endl;
        int h = st.query(cl, cr);
        // st.debug();
        // cout << h << endl;

        a[j] = h;
        st.update(cl,cr,h-1);
    }

    rep(i,0,k){
        cout << a[i] << endl;
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

