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
//     public:
//         vector<int> findEvenNumbers(vector<int>& v) {
//             int n = v.size();
//             set<int> s;

//             rep(i,0,n){
//                 rep(j,0,n){
//                     if(i==j) continue;
//                     rep(k,0,n){
//                         if(j==k or i==k) continue;
//                         int x = v[i]*100+v[j]*10+v[k];
//                         if(x>=100 and x%2==0) s.insert(x);
//                     }
//                 }
//             }

//             return vi(all(s));
//         }

//     };


class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& v) {
        vi c(10);
        int n = v.size();

        vi ans;

        rep(i,0,n) c[v[i]]++;

        rep(i,1,10){
            if(c[i]==0) continue;
            c[i]--;

            rep(j,0,10){
                if(c[j]==0) continue;
                c[j]--;

                for(int k=0; k<10; k+=2){
                    if(c[k]==0) continue;

                    ans.pb(i*100+j*10+k);
                }
                c[j]++;
            }

            c[i]++;
        }

        return ans;
    }
};