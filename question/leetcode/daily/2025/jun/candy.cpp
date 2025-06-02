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


// class Solution {
// public:
//     int candy(vector<int>& v) {
//         int n = v.size();

//         vii v2;
//         rep(i,0,n){
//             v2.pb({v[i],i});
//         }

//         sort(all(v2));

//         int a = 0;
//         vi v3(n);

//         rep(i,0,n){
//             auto [_,j] = v2[i];

//             int m = 1;
//             if(j-1>=0 and v[j-1]<v[j]) m = max(m,v3[j-1]+1);
//             if(j+1<n and v[j+1]<v[j]) m = max(m,v3[j+1]+1);

//             v3[j] = m;
//             a+=m;
//         }

//         return a;
//     }
// };

class Solution {
public:
    int candy(vector<int>& v) {
        int n = v.size();

        vi vl(n,1);
        vi vr(n,1);

        rep(i,1,n){
            if(v[i]>v[i-1]) vl[i] = vl[i-1]+1;
        }
        repr(i,n-2,-1){
            if(v[i]>v[i+1]) vr[i] = vr[i+1]+1;
        }

        int a = 0;

        rep(i,0,n){
            a+=max(vl[i],vr[i]);
        }

        return a;
    }
};