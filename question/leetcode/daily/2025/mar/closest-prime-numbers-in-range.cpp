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

vi soe(int n){
    vi soe(n+1, -1);

    for(int i=2;i<=n;i++){
        if(soe[i]!=-1) continue;
        // cout << i << endl;
        soe[i] = 1;
        for(int j=i*2;j<=n;j+=i){
            // cout << j << endl;
            soe[j] = i;
        }
    }

    return soe;
}


class Solution {
    public:
        vector<int> closestPrimes(int l, int r) {
            vi s = soe(r);
            vi v;
            rep(i,l,r+1){
                if(s[i]==1){
                    v.pb(i);  
                }
            }
            

            int n = v.size();
            if(n<2){
                return {-1,-1};
            }
            vi a = {v[0], v[1]};

            rep(i,1,n){
                if(v[i]-v[i-1] < a[1]-a[0]){
                    a = {v[i-1], v[i]};
                }
            }

            return a;
        }
    };
