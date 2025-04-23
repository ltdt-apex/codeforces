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

class Solution {
    public:
        int minDifference(vector<int>& v) {
            int n = v.size();

            ll l = INT_MAX;
            ll r = 0;
            ll m = 0;

            rep(i,0,n){
                if(((i-1>=0 and v[i-1]==-1) or (i+1<n and v[i+1]==-1)) and v[i]!=-1){
                    r = max(r, (ll)v[i]);
                    l = min(l, (ll)v[i]);
                }
                if(i>=1 and v[i]!=-1 and v[i-1]!=-1){
                    m = max(m, (ll)abs(v[i]-v[i-1]));
                }
            }

            // cout << l << " " << r << " " << m << endl;

            ll k = max(m, (r-l+1)/2);
            ll j = k;

            auto ok = [&] (ll d) {
                ll x = l+d;
                ll y = r-d;
                ll c = 0;

                ll p = -1;

                rep(i,0,n){
                    if(v[i]==-1){
                        c++;
                        if(p!=-1) if(min(abs(p-x), abs(p-y)) > d) return false;
                    }
                    else{
                        if(p!=-1 and c!=0) {
                            if(c==1){
                                if(min(max(abs(p-x), abs(v[i]-x)), max(abs(p-y), abs(v[i]-y))) > d) return false;
                            }
                            if(c>=2){
                                int pass = 0;
                                if(max(abs(p-x), abs(v[i]-x)) <= d) pass = 1;
                                if(max(abs(p-y), abs(v[i]-y)) <= d) pass = 1;
                                if(max(min(abs(p-x), abs(p-y)), min(abs(v[i]-x), abs(v[i]-y))) <= d and abs(x-y) <= d) pass = 1;
                                if(not pass) return false;
                            }
                        }
                        if(c!=0 and min(abs(v[i]-x), abs(v[i]-y)) > d) return false;

                        p=v[i];
                        c=0;
                    }
                }

                return true;
            };

            while(k){
                while(j-k>=m and ok(j-k)) j-=k;
                k/=2;
            }

            return j;
        }
    };