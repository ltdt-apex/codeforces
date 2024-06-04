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

// https://cp-algorithms.com/data_structures/segment_tree.html
// segment tree
// O(n) build
// O(log n) query
// O(log n) update

// O(n) in memory
struct ST {
    ll n;
    vi t;

    ST(vi& a): n(a.size()), t(4*n) {
        build(a, 1, 0, n-1);
    }

    int combine(int a, int b){
        return a & b;
        // return max(a,b);
        // return min(a,b);
    }

    void build(vi& a, int v, int tl, int tr){
        if(tl==tr) t[v] = a[tl];
        else {
            int tm = (tl+tr)/2;
            build(a, v*2, tl, tm);
            build(a, v*2+1, tm+1, tr);
            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    int query(int v, int tl, int tr, int l, int r){
        if(l>r) return ~0;
        // if(l>r) return LONG_LONG_MAX; // for min queries
        if (l==tl and r==tr) {
            return t[v];
        }

        int tm = (tl+tr)/2;
        return combine(query(v*2, tl, tm, l, min(r,tm)),
            query(v*2+1, tm+1, tr, max(l,tm+1), r));
    }

    int query(int l, int r){
        return query(1, 0, n-1, l, r);
    }

    // void update(int v, int tl, int tr, int pos, int new_v){
    //     if (tl==tr) {
    //         t[v] = new_v;
    //     }
    //     else{
    //         int tm = (tl+tr)/2;
    //         if(pos <= tm) update(v*2, tl, tm, pos, new_v);
    //         else update(v*2+1, tm+1, tr, pos, new_v);

    //         t[v] = combine(t[v*2], t[v*2+1]);
    //     }
    // }

    // void update(int pos, int new_v){
    //     update(1, 0, n-1, pos, new_v);
    // }

    void debug(int v, int tl, int tr){
        cout << v << " " << tl << "-" << tr << " " << t[v] << endl;
        if (tl==tr) return;
        
        int tm = (tl+tr)/2;
        debug(v*2, tl, tm),
        debug(v*2+1, tm+1, tr);
    }

    void debug(){
        debug(1, 0, n-1);
    }
};


class Solution {
public:
    int minimumDifference(vector<int>& v, int x) {
        ll n = v.size();

        ST st = ST(v);

        int a = INT_MAX;
        
        rep(i,0,n){
            ll j = 0;
            for(int k=n;k>=1;k/=2){
                while(j+k<=i and st.query(j+k,i) <= x) {
                    j+=k;
                };
            }
            
            a = min(a, abs(x - st.query(j,i)));
            if (j+1 <= i) a = min(a, abs(x - st.query(j+1,i)));
        }

        return a;
    }
};