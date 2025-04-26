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


// class Solution {
// public:
//     long long countSubarrays(vector<int>& v, int mi, int ma) {
//         if(mi>ma) return 0;
//         ll a = 0;
//         int n = v.size();
//         vi dp(2);
//         int l = 0;
//         int ls = 0;

//         rep(i,0,n){
//             if(v[i]<mi or v[i]>ma){
//                 // cout<<"hi"<<endl;
//                 dp = {0,0};
//                 l = i+1;
//                 ls = i+1;
//             }

//             if(v[i]==mi){
//                 dp[0]++;
//             }
//             if(v[i]==ma){
//                 dp[1]++;
//             }
            
//             while(dp[0]>=1 or dp[1]>=1){
//                 // cout << "l: " << l << endl;
//                 if(v[l] == mi) {
//                     if (dp[0]>1) dp[0]--;
//                     else break;
//                 }
//                 if(v[l] == ma) {
//                     if(dp[1]>1) dp[1]--;
//                     else break;
//                 }

//                 l++;
//             }

//             // cout << i << endl;
//             if(dp[0]>=1 and dp[1]>=1){
//                 // cout << ls << " " << l << " " << l-ls+1 << endl;
//                 a+=l-ls+1;
//             }
//         }

//         return a;
//     }
// };

class Solution {
    public:
        long long countSubarrays(vector<int>& v, int mi, int ma) {
            ll a = 0;
            int n = v.size();

            int lmi = -1;
            int lma = -1;
            int start = 0;

            rep(i,0,n){
                if(v[i]<mi or v[i]>ma) start = i+1;
                if(v[i]==mi) lmi = i;
                if(v[i]==ma) lma = i;

                if(start<=lmi and start<=lma) a+= min(lmi,lma)-start+1;
            }

            return a;
        }
    };