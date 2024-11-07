// @prefix template
// @description 

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
    int findRotateSteps(string v, string k) {
        int n = v.size();
        int m = k.size();

        unordered_map<char, vi> map;
        map['#'] = {0};

        rep(i,0,n){
            map[v[i]].pb(i);
        }
        
        char lc = '#';

        vi dp(n, INT_MAX);
        dp[0] = 0;

        rep(i,0,m){
            char c = k[i];
            int li = 0;
            vi& lv = map[lc];
            int lm = lv.size();
            for(auto j: map[c]){
                while(li < lm and lv[li] < j){
                    li++;
                }

                int li1 = lv[(li+lm-1)%lm];
                int li2 = lv[(li+lm)%lm];

                dp[j] = min(dp[li1] + min(abs(j-li1), n-abs(j-li1)), dp[li2] + min(abs(j-li2), n-abs(j-li2)));
            }
            lc = c;
        }

        int a = INT_MAX;
        for(auto i: map[k.back()]){
            a = min(a, dp[i]);
        }

        return a+m;
    }
};