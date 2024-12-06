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
    bool canChange(string s1, string s2) {
        int n = s1.size();

        vi p1;
        rep(i,0,n){
            if(s1[i] == 'L') p1.pb(1);
            if(s1[i] == 'R') p1.pb(2);
        }
        vi p2;
        rep(i,0,n){
            if(s2[i] == 'L') p2.pb(1);
            if(s2[i] == 'R') p2.pb(2);
        }

        if(p1.size()!=p2.size()) return false;
        rep(i,0,p1.size()){
            if(p1[i]!=p2[i]) return false;
        }

        int ls = 0;
        rep(i,0,n){
            if(s1[i] == 'L') ls++;
            if(s2[i] == 'L') ls--;

            if(ls>0) return false;
        }
        int rs = 0;
        repr(i,n-1,-1){
            if(s1[i] == 'R') rs++;
            if(s2[i] == 'R') rs--;

            if(rs>0) return false;
        }

        return true;
    }
};