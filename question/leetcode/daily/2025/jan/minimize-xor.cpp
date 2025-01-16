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

class Solution {
public:
    int minimizeXor(int n1, int n2) {
        int b1 = 0;
        int b0 = 0;

        while(n2){
            if(n2%2) b1++;
            else b0++;

            n2/=2;
        }

        int b = 0;
        int c = b0+b1;

        vi v;

        while(n1){
            v.pb(n1%2);
            n1/=2;
        }
        reverse(all(v));
        int n = v.size();

        vi v2(n);
        rep(i,0,n){
            if(v[i]==1 and b1>0){
                v2[i]=1;
                b1--;
            }
        }

        // for(auto x: v2){
        //     cout << x;
        // }cout << endl;

        repr(i,n-1,-1){
            if(v[i]==0 and b1>0){
                v2[i]=1;
                b1--;
            }
        }

        // for(auto x: v2){
        //     cout << x;
        // }cout << endl;

        reverse(all(v2));
        while(b1>0){
            b1--;
            v2.pb(1);
        }

        // for(auto x: v2){
        //     cout << x;
        // }cout << endl;

        ll a = 0;
        ll p = 1;
        for(auto x: v2){
            a+=p*x;
            p*=2;
        }

        return a;
    }
};

