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
    Type type;
    int n = 0;
    vector<T> t;
    
    ST(vector<T>& a, Type type = Type::NORMAL): type(type), n(a.size()), t(4*n) {
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
        if(type == Type::NORMAL) return a + b;
        if(type == Type::MAX) return max(a,b);
        if(type == Type::MIN) return min(a,b);

        assert(false);
    }

    T default_outbound_return(){
        if (type == Type::NORMAL) return 0;
        if (type == Type::MAX) return -numeric_limits<T>::max();;
        if (type == Type::MIN) return numeric_limits<T>::max();

        assert(false);
    }

    void default_update(T& a, T b, updateType update_type){
        if(update_type == ASSIGNMENT) a=b;
        if(update_type == DELTA) a+=b;
    }

    T query(int i, int tl, int tr, int l, int r){
        if(l>r) {
            return default_outbound_return();
        }

        if (l==tl and r==tr) {
            return t[i];
        }

        int tm = (tl+tr)/2;
        return combine(
            query(i*2, tl, tm, l, min(r,tm)),
            query(i*2+1, tm+1, tr, max(l,tm+1), r)
        );
    }

    void update(int i, int tl, int tr, int pos, T v, updateType update_type){
        if (tl==tr) {
            default_update(t[i], v, update_type);
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

class Solution {
public:
    long long maxRectangleArea(vector<int>& js, vector<int>& is) {
        int n = js.size();

        vii ps(n);
        
        set<ll> xs;

        rep(i,0,n){
            ps[i] = {is[i], js[i]};
            xs.insert(js[i]);
        }

        sort(all(ps));

        unordered_map<ll, ll> xmaxy;
        unordered_map<ll, ll> xindex;

        vl xsv(xs.size(), -LONG_LONG_MAX);
        ll ci = 0;
        for(auto v: xs){
            xindex[v] = ci;
            ci++;
        }

        ST st(xsv, MAX);

        ll a = -1;

        rep(i,0,n-1){
            pll p1 = {ps[i].f, ps[i].s};
            pll p2 = {ps[i+1].f, ps[i+1].s};

            int valid = 1;
            if(p1.f!=p2.f) valid = 0;

            if((not xmaxy.count(p1.s)) or (not xmaxy.count(p2.s)) or (xmaxy[p1.s] == -LONG_LONG_MAX) or not (xmaxy[p1.s] == xmaxy[p2.s])) valid = 0;

            // cout << st.query(xindex[p1.s], xindex[p2.s]) << " " << xmaxy[p1.s] << endl;
            if(st.query(xindex[p1.s]+1, xindex[p2.s]-1) >= xmaxy[p1.s]) valid = 0;
            // cout << valid << endl;

            // if(valid) cout << p1.f << " " << p1.s << " " << p2.f << " " << p2.s << " " << xmaxy[p1.s] << " " << xmaxy[p2.s] << endl;
            // if(valid) cout << st.query(xindex[p1.s], xindex[p2.s]) << " " << xmaxy[p1.s] << endl;
            if(valid) a = max(a, (p1.f - xmaxy[p1.s])*(p2.s-p1.s));

            st.update(xindex[p1.s], p1.f);
            xmaxy[p1.s] = p1.f;
        }

        return a;
    }
};