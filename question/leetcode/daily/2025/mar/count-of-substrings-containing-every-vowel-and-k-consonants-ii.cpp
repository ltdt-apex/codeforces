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
        long long countOfSubstrings(string s, int k) {
            int n = s.size();

            int l1 = 0;
            int l2 = 0;
            int c2 = 0;
            vi dp(5);
            ll a = 0;

            unordered_map<char,int> m;
            m['a'] = 0;
            m['e'] = 1;
            m['i'] = 2;
            m['o'] = 3;
            m['u'] = 4;

            rep(r,0,n){
                char c = s[r];
                if(not m.count(c)){
                    c2++;

                    while(c2>k){
                        if(not m.count(s[l2])){
                            c2--;
                        }
                        else{
                            dp[m[s[l2]]]--;
                        }
                        l2++;
                        l1 = l2;
                    }
                }
                else{
                    dp[m[c]]++;
                }

                while(l2<r){
                    if(not m.count(s[l2])){
                        break;
                    }
                    else{
                        if(dp[m[s[l2]]]<=1) break;
                        dp[m[s[l2]]]--;
                    }
                    l2++;
                }

                int ok = 1;

                if(c2<k) ok=0;
                rep(i,0,5){
                    if(dp[i]==0) ok=0;
                }

                if(ok) a+=l2-l1+1;
            }

            return a;
        }
    };