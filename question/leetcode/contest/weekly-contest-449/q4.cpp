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
const ll p5 = pow(10,5);

vii dirs = {{-1,0},{1,0},{0,-1},{0,1}};
vii dirs8 = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};


class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        vi s1(pow(10,5)+1);
        vi s2(pow(10,5)+1);

        ll a = 0;
        rep(i,0,n){
            rep(j,0,m){
                a+=v[i][j];
                s1[v[i][j]]++;
                s2[v[i][j]]++;
            }
        }

        ll a1 = 0;
        vi sn(pow(10,5)+1);

        rep(i,0,n-1){
            rep(j,0,m){
                a1+=v[i][j];
                sn[v[i][j]]++;
                s1[v[i][j]]--;
            }
            ll a2 = a-a1;
            ll d = abs(a1-a2);

            if(d>p5) continue;

            if(a1==a2) return true;
            else if(a1<a2){
                if(m==1){
                    if(v[i+1][0]==d or v[n-1][0]==d) return true;
                }
                else if(i==n-2){
                    if(v[n-1][0]==d or v[n-1][m-1]==d) return true;
                }
                else if(s1[d]!=0) return true;
            }
            else{
                if(m==1){
                    if(v[0][0]==d or v[i][0]==d) return true;
                }
                else if(i==0){
                    if(v[0][0]==d or v[0][m-1]==d) return true;
                }
                else if(sn[d]!=0) return true;
            }
        }

        sn.clear();

        a1 = 0;
        rep(j,0,m-1){
            rep(i,0,n){
                a1+=v[i][j];
                sn[v[i][j]]++;
                s2[v[i][j]]--;
            }
            ll a2 = a-a1;
            ll d = abs(a1-a2);

            if(d>p5) continue;

            if(a1==a2) return true;
            else if(a1<a2){
                if(n==1){
                    if(v[0][j+1]==d or v[0][m-1]==d) return true;
                }
                else if(j==m-2){
                    if(v[0][m-1]==d or v[n-1][m-1]==d) return true;
                }
                else if(s2[d]!=0) return true;
            }
            else{
                if(n==1){
                    if(v[0][0]==d or v[0][j]==d) return true;
                }
                else if(j==0){
                    if(v[0][0]==d or v[n-1][0]==d) return true;
                }
                else if(sn[d]!=0) return true;
            }
        }

        return false;
    }
};
