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
    int countWinningSequences(string s) {
        int n = s.size();
        vvvi dp(2, vvi(2001, vi(3)));

        int b = 1000;

        unordered_map<char, int> m ={
            {'F', 0},
            {'W', 1},
            {'E', 2},
        };

        int c = m[s[0]];
        
        dp[0][b][c] = 1;
        dp[0][b+1][(c+1)%3] = 1;
        dp[0][b-1][(c-1+3)%3] = 1;

        rep(i,1,n){
            c = m[s[i]];

            rep(j,0,2001){
                rep(k,0,3){
                    if(c==k){
                        dp[i%2][j][k] = dp[(i-1)%2][j][(k+1)%3] + dp[(i-1)%2][j][(k-1+3)%3];
                        dp[i%2][j][k]%=mod;
                    }

                    else if((c+1)%3 == k){
                        if(j>0){
                            dp[i%2][j][k] = dp[(i-1)%2][j-1][(k+1)%3] + dp[(i-1)%2][j-1][(k-1+3)%3];
                            dp[i%2][j][k]%=mod;
                        }
                    }

                    else{
                        if(j<2000){
                            dp[i%2][j][k] = dp[(i-1)%2][j+1][(k+1)%3] + dp[(i-1)%2][j+1][(k-1+3)%3];
                            dp[i%2][j][k]%=mod;
                        }
                    }
                }
            }
        }

        int a = 0;

        rep(i,b+1,2001){
            rep(k,0,3){
                a+=dp[(n-1)%2][i][k];
                a%=mod;
            }
        }

        return a;
    }
};
