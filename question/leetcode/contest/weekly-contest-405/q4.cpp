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

struct Trie {
    unordered_map<char, Trie*> node;
    int score;

    Trie() : score(INT_MAX) {}
};

class Solution {
public:
    int minimumCost(string t, vector<string>& v, vector<int>& c) {
        ll n = t.size();
        ll m = v.size();

        Trie *trie = new Trie();

        rep(i,0,m){
            string w = v[i];
            reverse(all(w));
            Trie *cur = trie;
            for (auto c: w){
                if(!cur->node[c]) cur->node[c] = new Trie();
                cur = cur->node[c];
            }
            cur->score = min(cur->score, c[i]);
        }

        vi dp(n+1, INT_MAX);
        dp[0] = 0;

        rep(i,0,n){
            int j = i;
            Trie* cur = trie;
            while(j>=0 and cur->node[t[j]]){
                cur = cur->node[t[j]];

                if(cur->score != INT_MAX and dp[j] != INT_MAX) dp[i+1] = min(dp[i+1], dp[j] + cur->score);
                j--;
            }
        }

        if(dp.back() == INT_MAX) return -1;

        return dp.back();

    }
};