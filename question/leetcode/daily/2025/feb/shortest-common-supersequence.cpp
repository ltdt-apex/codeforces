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
        string shortestCommonSupersequence(string s1, string s2) {
            int n = s1.size();
            int m = s2.size();
            vvi dp(n+1, vi(m+1));

            rep(i,0,n){
                rep(j,0,m){
                    if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j]+1;
                    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }

            string a;

            int i = n-1;
            int j = m-1;

            while(i>=0 and j>=0){
                if(s1[i]==s2[j]){
                    a+=s1[i];
                    i--;
                    j--;
                }
                else if(dp[i][j+1] > dp[i+1][j]){
                    a+=s1[i];
                    i--;
                }
                else{
                    a+=s2[j];
                    j--;
                }
            }

            while(i>=0){
                a+=s1[i];
                i--;
            }

            while(j>=0){
                a+=s2[j];
                j--;
            }

            reverse(all(a));

            return a;
        }
    };