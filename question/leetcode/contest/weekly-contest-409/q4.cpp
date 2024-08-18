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
        return a + b;
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
        if(l>r) return 0;
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

    void update(int v, int tl, int tr, int pos, int new_v){
        if (tl==tr) {
            t[v] += new_v;
        }
        else{
            int tm = (tl+tr)/2;
            if(pos <= tm) update(v*2, tl, tm, pos, new_v);
            else update(v*2+1, tm+1, tr, pos, new_v);

            t[v] = combine(t[v*2], t[v*2+1]);
        }
    }

    void update(int pos, int new_v){
        update(1, 0, n-1, pos, new_v);
    }

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

// void f1(int& l, int& r, int n){
//     if(r-l+1>n){
//         l = 0;
//         r = n-1;
//     }
// }

bool valid(int l, int r, int n){
    if(l >= n) return false;
    return true;
}

class Solution {
public:
    vector<int> numberOfAlternatingGroups(vector<int>& c, vector<vector<int>>& q) {
        int n = c.size();
        int m = q.size();

        vi x(2*n+1,0);
        ST st1(x);
        ST st2(x);

        set<pii> s;

        rep(i,0,n){
            c.pb(c[i]);
        }

        vi a;

        int l = 0;
        while (l < n*2){
            int r = l;
            while(r+1<n*2 and c[r]!=c[r+1]){
                r++;
            }
            s.insert({l,r});
            int tr = r;
            if (valid(l,r,n)){
                st1.update(r-l+1, 1);
                st2.update(r-l+1, r-l+1);
            }
            l=tr;
            l++;
        }

        // auto it1 = s.begin();
        // auto it2 = prev(s.end());
        // if((*it2).s >= n){
        //     auto [l,r] = *it1;
        //     st1.update(r-l+1, -1);
        //     st2.update(r-l+1, -(r-l+1));
        // }

        // for(auto [l,r]: s){
        //     cout << l << ' ' << r << endl;
        // }

        // st1.debug();
        // cout << endl;


        for (auto x: q){
            int t = x[0];
            if(t==1){
                auto it1 = s.begin();
                auto it2 = prev(s.upper_bound({n,INT_MAX}));
                auto [l,r] = *it1;

                // cout << (*it2).s << " " << (*it2).f << endl;
                if((*it2).f < n and (*it2).s-(*it2).f+1 <= n){
                    // cout << "test- " << endl;
                    st1.update(r-l+1, -1);
                    st2.update(r-l+1, -(r-l+1));
                }

                // for(auto [l,r]: s){
                //     cout << l << ' ' << r << endl;
                // }

                // st1.debug();
                // cout << endl;
                // st2.debug();
                // cout << endl;

                int size = x[1];
                int s1 = st1.query(size, size+n-1);
                int s2 = st2.query(size, size+n-1);
                int s3 = st1.query(size+n, 2*n);
                a.pb(s2-(size-1)*s1 + s3*n);

                if((*it2).f < n and (*it2).s-(*it2).f+1 <= n){
                    st1.update(r-l+1, 1);
                    st2.update(r-l+1, r-l+1);
                }
            }
            if(t==2){
                if (c[x[1]] == x[2]) continue;
                vi ui = {x[1], x[1]+n};
                for (auto i: ui){
                    c[i] = x[2];
                    // cout << i << endl;
                    int ll, lr, rl, rr;
                    if(i-1==-1){
                        ll = -1;
                        lr = -1;
                    }
                    else{
                        tie(ll, lr) = *prev(s.upper_bound({i-1,INT_MAX}));
                    }
                    if(i+1==n*2){
                        rl = n*2;
                        rr = n*2;
                    }
                    else{
                        tie(rl, rr) = *prev(s.upper_bound({i+1,INT_MAX}));;
                    }

                    // cout << ll << " " << lr << " " << rl << ' ' << rr << endl;

                    set<pii> rs;
                    rs.insert({ll,lr});
                    rs.insert({rl,rr});
                    if (lr<i and i<rl) rs.insert({i,i});

                    // cout << "rs" << endl;
                    for(auto [l,r]: rs){
                        // cout << l << ' ' << r << endl;

                        if (l==-1 or r==n*2) continue;
                        if (not s.count({l,r})) continue;
                        s.erase({l,r});
                        if(not (valid(l,r,n))) continue;
                        // cout << "-" << r-l+1 << endl;
                        st1.update(r-l+1, -1);
                        st2.update(r-l+1, -(r-l+1));
                    }

                    if(ll == rl and lr==rr){
                        lr = i-1;
                        rl = i+1;
                    }else{
                        if(ll != -1){
                            if(lr==i-1) lr++;
                            else lr--;
                        }
                        if(rr != n*2){
                            if(rl==i+1) rl--;
                            else rl++;
                        }

                        if(lr==rl){
                            lr = rr;
                            rl = ll;
                        }
                    }

                    // cout << ll << " " << lr << " " << rl << ' ' << rr << endl;


                    set<pii> ns;
                    ns.insert({ll,lr});
                    ns.insert({rl,rr});
                    if (lr<i and i<rl) ns.insert({i,i});

                    // cout << "ns" << endl;
                    for(auto [l,r]: ns){
                        // cout << l << ' ' << r << endl;
                        if (l==-1 or r==n*2) continue;
                        if (s.count({l,r})) continue;
                        s.insert({l,r});
                        if(not (valid(l,r,n))) continue;
                        // cout << "+" << r-l+1 << endl;
                        st1.update(r-l+1, 1);
                        st2.update(r-l+1, r-l+1);
                    }

                }

                // for(auto [l,r]: s){
                //     cout << l << ' ' << r << endl;
                // }

                // st1.debug();
                // cout << endl;
                
            }
        }

        return a;
    }
};


