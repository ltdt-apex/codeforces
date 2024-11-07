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
    int maxGoodNumber(vector<int>& v) {
        vl a(3);
        rep(i,0,3){
            int x = 1;
            int n = v[i];
            int b = 0;
            while(n){
                b+=(n%2)*x;
                x*=10;
                n/=2;
            }
            a[i] = b;
        }

        vector<string> ans;
        ans.pb(to_string(a[0]) + to_string(a[1]) + to_string(a[2]));
        ans.pb(to_string(a[0]) + to_string(a[2]) + to_string(a[1]));
        ans.pb(to_string(a[1]) + to_string(a[0]) + to_string(a[2]));
        ans.pb(to_string(a[1]) + to_string(a[2]) + to_string(a[0]));
        ans.pb(to_string(a[2]) + to_string(a[0]) + to_string(a[1]));
        ans.pb(to_string(a[2]) + to_string(a[1]) + to_string(a[0]));
        
        
        string t = *max_element(all(ans));
        int r = 0;
        int x = 1;

        repr(i,t.size()-1,-1){
            r+=(t[i]-'0')*x;
            x*=2;
        }

        return r;
    }
};
