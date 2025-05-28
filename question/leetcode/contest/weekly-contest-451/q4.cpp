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
#define range(i,b) for (int i = 0; i < b; i++)
#define rep(i,a,b) for (int i = a; i < b; i++)
#define repr(i,a,b) for (int i = a; i > b; i--)
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
    int empty(int i, int j, vvi& dpe, string& s){
        if((j-i+1)%2) return 0;

        if(i>j) return dpe[i][j] = 1;
        if(dpe[i][j]!=-1) return dpe[i][j];

        int a = 0;
        if(abs(s[i]-s[j])==1 or abs(s[i]-s[j])==25) a |= empty(i+1,j-1,dpe,s);
        rep(k,i+1,j-1){
            a |= (empty(i,k,dpe,s) and empty(k+1,j,dpe,s));
        }

        return dpe[i][j] = a;
    };

    string dfs(int i, int n, vector<string>& dp, vvi& dpe, string& s){
        if(i>=n) return "";
        
        if(dp[i]!="-1") return dp[i];
        
        string ans = s[i]+dfs(i+1,n,dp,dpe,s);
        
        rep(k,i+1,n){
            if(dpe[i][k]==1)
            ans = min(ans, dfs(k+1,n,dp,dpe,s));
        }
        // cout << i << " " << ans << endl;
        
        return dp[i] = ans;
    };
    
    string lexicographicallySmallestString(string s) {
        int n = s.size();
        vvi dpe(n, vi(n,-1));

        rep(i,0,n){
            rep(j,i+1,n){
                empty(i,j,dpe,s);
            }
        }

        vector<string> dp(n, "-1");

        return dfs(0,n,dp,dpe,s);

        return "";
    }
};
