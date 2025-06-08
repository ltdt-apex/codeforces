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
    int countPartitions(vector<int>& v, int k) {
        int n = v.size();

        deque<int> dma;
        deque<int> dmi;
        int l = 0;
        vl dp(n+1);
        dp[0] = 1;
        vl pdp(n+1);
        pdp[0] = 1;

        rep(i,0,n){
            while(not dma.empty() and v[dma.back()]<v[i]) dma.pop_back();
            while(not dmi.empty() and v[dmi.back()]>v[i]) dmi.pop_back();

            dma.pb(i);
            dmi.pb(i);

            // cout << "minmax: " << dmi.front() << " " << dmi.back() << " " << dma.front() << endl;
            // cout << dmi.size() << " " << dma.size() << endl;

            while(v[dma.front()]-v[dmi.front()]>k){
                l++;
                if(dma.front()<l) dma.pop_front();
                if(dmi.front()<l) dmi.pop_front();
            }

            // cout << "minmax: "  << dmi.front() << " " << dma.front() << endl;
            // cout << dmi.size() << " " << dma.size() << endl;
            // cout << l << " " << i << endl;

            if(l-1>=0) dp[i+1] = (pdp[i] - pdp[l-1]+mod)%mod;
            else dp[i+1] = pdp[i];
            pdp[i+1] = (dp[i+1] + pdp[i])%mod;

            // cout << dp[i+1] << endl;
        }

        return dp.back();
    }
};

