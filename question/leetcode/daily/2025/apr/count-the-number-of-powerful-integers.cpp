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
        ll dfs(int n, vi& num, int lim, string& s){
            // cout << isl << endl;
            vvl dp(n, vl(2));

            rep(i,0,n){
                rep(j,0,lim+1){
                    if(i==0){
                        if(j<num[i]) dp[i][0]++;
                        else if(j==num[i]) dp[i][1]++;
                    }
                    else{
                        dp[i][0]+=dp[i-1][0];
                        if(j<num[i]){
                            dp[i][0]+=dp[i-1][1];
                        }
                        else if(j==num[i]){
                            dp[i][1]+=dp[i-1][1];
                        }
                    }
                }
            }

            rep(i,0,s.size()){
                if(s[i]-'0' > num[n+i]){
                    // cout << s[i]-'0' << " " << num[n+i] << endl;
                    if(n==0) return 0;
                    else return dp[n-1][0];
                }
                else if(s[i]-'0' < num[n+i]){
                    // cout << dp[n-1][0] << " " << dp[n-1][1] << endl;
                    if(n==0)return 1;
                    else return dp[n-1][0]+dp[n-1][1];
                }
            }
            if(n==0)return 1;
            else return dp[n-1][0]+dp[n-1][1];
        }

        long long numberOfPowerfulInt(long long l, long long r, int lim, string s) {
            for(auto c: s){
                if(c-'0'>lim) return 0;
            }

            int n = 0;
            ll x = r;
            vi rs;

            while(x){
                rs.pb(x%10);
                x/=10;
                n++;
            }

            
            x = l-1;
            vi ls;
            while(x){
                ls.pb(x%10);
                x/=10;
            }
            while(ls.size()<rs.size()){
                ls.pb(0);
            }
            
            reverse(all(rs));
            reverse(all(ls));

            // rep(i,0,n){
            //     cout << ls[i] << ' ';
            // }cout << endl;
            // rep(i,0,n){
            //     cout << rs[i] << ' ';
            // }cout << endl;

            n-=s.size();
            if(n<0) return 0;

            ll rn = dfs(n,rs,lim,s);
            ll ln = dfs(n,ls,lim,s);
            // cout << rn << " " << ln << endl;
            
            return rn-ln;
        }
    };