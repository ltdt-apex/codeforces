#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

typedef pair<int, int> pii;
typedef vector<pair<int,int>> vii;
typedef vector<vector<pair<int,int>>> vvii;
typedef vector<tuple<int, int, int>> viii;
typedef vector<vector<tuple<int, int, int, int>>> vviiii;

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
    vector<int> treeQueries(int n, vector<vector<int>>& es, vector<vector<int>>& qs) {
        /*
        cheat on offline queries
        dfs on tree, for each node

        1. update delta change of weight for current edge 
        (parent -> current) on seg tree,

        2. answer query on current node 
        which is 
            original sum weight + 
            delta change in seg tree (from the range of 0 to query index-1), 

        3. undo delta change after dfs
        */
        vvi adj(n+1);

        int m = es.size();
        unordered_map<int, unordered_map<int, int>> we;

        rep(i,0,m){
            int u = es[i][0];
            int v = es[i][1];
            int w = es[i][2];

            adj[u].pb(v);
            adj[v].pb(u);
            if(u>v) swap(u,v);
            we[u][v] = w;
            // cout << u << ' ' << v << " " << w << endl; 
        }

        int c2 = 0;

        int m2 = qs.size();
        unordered_map<int, unordered_map<int, vii>> up;
        vvii in(n+1);
        
        rep(i,0,m2){
            if(qs[i][0] == 1){
                int u = qs[i][1];
                int v = qs[i][2];
                int w = qs[i][3];
                if(u>v) swap(u,v);
                up[u][v].pb({i,w});
                up[v][u].pb({i,w});
            }
            else{
                int u = qs[i][1];
                in[u].pb({i,c2});
                c2++;
            }
        }

        vi a(c2);
        
        vi t(m2);
        ST st(t);

        auto dfs = [&](auto&& dfs, int p, int u, int pw) -> void{
            // cout << "dfs: " <<  p << " " << u << endl;
            int tp = p;
            int tu = u;
            if(tp>tu) swap(tp,tu);
            
            int cw = 0;
            if(p!=-1) cw = we[tp][tu];
            int tw = cw+pw;
            
            // cout << up[tp][tu].size() << endl;
            if(p!=-1){
                rep(j,0,up[tp][tu].size()){
                    // cout << j << endl;
                    auto [si, nw] = up[tp][tu][j];
                    // cout << cw << " " << nw << endl;
                    int dw = nw-cw;
                    cw = nw;
                    st.update(si, dw);
                }
            }
            
            vii& cin_ = in[u];
            int m3 = cin_.size();
            // cout << u << endl;
            // st.debug();
            rep(i,0,m3){
                auto [qi, ai] = cin_[i];

                a[ai] = st.query(0,qi-1) + tw;
            }

            for(auto v: adj[u]){
                if(v==p) continue;
                dfs(dfs,u,v,tw);
            }

            if (p==-1) return;
            rep(j,0,up[tp][tu].size()){
                auto [si, _] = up[tp][tu][j];
                st.update(si,0);
            }
        };

        dfs(dfs,-1,1,0);
        return a;
    }
};