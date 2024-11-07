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


class Solution {
public:
    int countPairs(vector<int>& v) {
        // TLE
        ll n = v.size();
        ll a = 0;
        rep(i,0,n){
            rep(j,0,i){
                string b = to_string(v[i]);
                string c = to_string(v[j]);

                ll m1 = b.size();
                ll m2 = c.size();
                ll m = max(m1,m2);

                b.insert(0,m-m1,'0');
                c.insert(0,m-m2,'0');

                string bt;
                string ct;
                rep(i,0,m){
                    if(b[i]!=c[i]){
                        bt+=b[i];
                        ct+=c[i];
                    }
                }

                if(bt.size() == 0) a++;
                if(bt.size() == 2 or bt.size() == 3){
                    sort(all(bt));
                    sort(all(ct));
                    if(bt==ct) a++;
                }
                if(bt.size() == 4){
                    int found = 0;
                    rep(d,0,4){
                        rep(e,0,d){
                            vl g1;
                            vl g2;
                            rep(f,0,4){
                                if(f==d or f==e) g1.pb(f);
                                else g2.pb(f);
                            }

                            if(bt[g1[0]] == ct[g1[1]] and bt[g1[1]] == ct[g1[0]] and 
                                bt[g2[0]] == ct[g2[1]] and bt[g2[1]] == ct[g2[0]]){
                                    found = 1;
                                }
                        }
                    }

                    if(found) a++;
                }
                // cout << i << ' ' << j << endl;
                // cout << a << endl; 
            }
        }

        return a;
    }
};


