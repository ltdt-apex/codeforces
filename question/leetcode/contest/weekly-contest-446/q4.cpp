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

struct da {
    int pa[5];
    int r;
};


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
    int k;
    
    ST(vi& a, int k, Type type = Type::NORMAL): type(type), n(a.size()), t(4*n) {
        this->k = k;
        // cout << this->k << endl;
        build(a, 1, 0, n-1);
    }

    // void debug(){
    //     vector<tuple<int, int, int, T>> nodes;
    //     findNodes(1, 0, n-1, nodes);

    //     sort(all(nodes), [&](auto a, auto b){
    //         auto [ai, atl, atr, av] = a;
    //         auto [bi, btl, btr, bv] = b;

    //         if(atr-atl == btr-btl){
    //             return atl < btl;
    //         }
    //         else return atr-atl < btr-btl;            
    //     });

    //     for(auto [i, tl, tr, v]: nodes){
    //         cout << i << " " << tl << "-" << tr << " " << endl;
    //         rep(j,0,k){
    //             cout << v.pa[j] << " ";
    //         }cout << endl;
    //     }
    // }

    // void findNodes(int i, int tl, int tr, vector<tuple<int, int, int, T>>& nodes){
    //     nodes.pb({i,tl,tr,t[i]});
    //     if (tl==tr) return;

    //     int tm = (tl+tr)/2;
    //     findNodes(i*2, tl, tm, nodes),
    //     findNodes(i*2+1, tm+1, tr, nodes);
    // }

    void build(vi& a, int i, int tl, int tr){
        if(tl==tr) default_update(t[i], a[tl]);
        else {
            int tm = (tl+tr)/2;
            build(a, i*2, tl, tm);
            build(a, i*2+1, tm+1, tr);
            t[i] = combine(t[i*2], t[i*2+1]);
        }
    }

    T combine(T a, T b){
        da c;
        
        rep(i,0,k){
            c.pa[i] = a.pa[i];
        }
        rep(i,0,k){
            c.pa[(a.r*i)%k]+=b.pa[i];
        }

        c.r = ((ll)a.r*(ll)b.r)%k;
        return c;

        assert(false);
    }

    T default_outbound_return(){
        // if (type == Type::NORMAL) return 0;
        // if (type == Type::MAX) return -numeric_limits<T>::max();;
        // if (type == Type::MIN) return numeric_limits<T>::max();

        da c;

        rep(i,0,k)c.pa[i] = 0;
        c.r = 1;

        return c;

        assert(false);
    }

    void default_update(T& a, int b, updateType update_type = ASSIGNMENT){
        // if(update_type == ASSIGNMENT) a=b;
        // if(update_type == DELTA) a+=b;
        b%=k;

        rep(i,0,k) a.pa[i] = 0;
        a.pa[b] = 1;
        a.r = b;
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

    void update(int i, int tl, int tr, int pos, int v, updateType update_type){
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

    void update(int pos, int new_v){
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
    vector<int> resultArray(vector<int>& v, int k, vector<vector<int>>& qs) {
        int n = v.size();

        ST<da> st(v, k);
        vi a;
        // st.debug();
        
        int m = qs.size();

        rep(i,0,m){
            st.update(qs[i][0], qs[i][1]);
            // cout << endl;
            // st.debug();
            
            // cout << qs[i][2] << ' ' << n-1 << endl;
            // vl de = st.query(qs[i][2], n-1).pa;
            // for(auto x: de){
            //     cout << x << " " << endl;
            // }

            a.pb(st.query(qs[i][2], n-1).pa[qs[i][3]]);
        }

        return a;
    }
};
