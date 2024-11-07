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
    vector<int> gcdValues(vector<int>& v, vector<long long>& q) {
        ll n = v.size();
        ll m = q.size();

        ll ma = *max_element(all(v));
        vl c(ma+1);

        rep(i,0,n){
            int x = v[i];

            for(int i=1;i*i<=x;i++){
                if(x%i==0) {
                    c[i]++;
                    if(i*i!=x) c[x/i]++;
                }
            }
        }

        vl np(ma+1);

        repr(i,ma,0){
            int t = c[i]*(c[i]-1)/2;
            for(int j = i*2; j<=ma; j+=i){
                t -= np[j];
            }

            np[i] = t;
        }


        rep(i,1,ma+1){
            np[i] += np[i-1];
        }

        // rep(i,0,ma+1){
        //     cout << np[i] << " ";
        // }cout << endl;

        vi a(m);

        rep(i,0,m){
            int x = q[i];

            int k = 0;
            int j = ma;
            while(j){
                while(j+k<=ma and x>=np[j+k]){
                    k+=j;
                }
                j/=2;
            }
            a[i] = k+1;
        }

        return a;
    }
};
