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
    int minOperations(string s1, string s2) {
        int n = s1.size();

        auto f = [&](string x, string y) -> int{
            unordered_map<int, unordered_map<int, int>> d;

            int t = 0;
            int a = 0;

            int m = x.size();

            rep(i,0,m){
                if(x[i]==y[i])continue;
                int c1 = x[i]-'a';
                int c2 = y[i]-'a';

                if(d[c2][c1]){
                    a++;
                    d[c2][c1]--;
                    t--;
                }
                else{
                    t++;
                    d[c1][c2]++;
                }
            }

            // cout << x << " " << y << " " << a+t << endl;
            return a+t;
        };

        vl dp(n+1, INT_MAX);
        dp[0] = 0;

        rep(i,1,n+1){
            rep(j,1,i+1){
                string x = s1.substr(j-1,i-j+1);
                string rx = x;
                reverse(all(rx));
                string y = s2.substr(j-1,i-j+1);

                dp[i] = min(dp[i], f(x,y)+dp[j-1]);
                dp[i] = min(dp[i], 1+f(rx,y)+dp[j-1]);
            }

            // cout << i << " " << dp[i] << endl;
        }

        return dp.back();
    }
};

