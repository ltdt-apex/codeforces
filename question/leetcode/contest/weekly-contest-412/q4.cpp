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

int get_digit(int x, int i){
    while(i--){
        x/=10;
    }
    return x%10;
}

class Solution {
public:
    int countPairs(vector<int>& v) {
        // stupid bound almost give TLE even with O(n * d**4)
        // it will TLE if you do full 4 nested loops in looping digits

        sort(rall(v));
        ll n = v.size();
        ll a = 0;
        unordered_map<int, int> m;

        for(auto x: v){
            a+=m[x];

            ll s = int(log10(x))+1;
            unordered_set<int> s1;

            rep(i,0,s){
                rep(j,0,i+1){
                    ll t = x;
                    ll c = get_digit(t,i), d = get_digit(t,j);
                    t-=c*pow(10,i);
                    t-=d*pow(10,j);
                    t+=d*pow(10,i);
                    t+=c*pow(10,j);
                    rep(k,0,i+1){
                        rep(l,0,k+1){
                            int t2 = t;
                            ll e = get_digit(t2,k), f = get_digit(t2,l);
                            t2-=e*pow(10,k);
                            t2-=f*pow(10,l);
                            t2+=f*pow(10,k);
                            t2+=e*pow(10,l);
                            s1.insert(t2);
                        }
                    }
                }
            }

            for(auto y: s1){
                // cout << y << " ";
                m[y]++;
            }
            // cout << endl;
        }

        return a;
    }
};


