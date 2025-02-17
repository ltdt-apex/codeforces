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

    int dfs(int i, int m, int n, vi& a, vi& used){
        while(i<m and a[i]!=-1) i++;

        if(i==m){
            return 1;
        }

        repr(j,n,0){
            if(used[j]) continue;

            if(j!=1){
                if(i+j>=m or a[i+j]!=-1) continue;
            }

            a[i] = j;
            if(j!=1) a[i+j] = j;
            used[j] = 1;
            if(dfs(i+1,m,n,a,used)) return 1;
            a[i] = -1;
            if(j!=1) a[i+j] = -1;
            used[j] = 0;
        }

        return 0;
    }

    vector<int> constructDistancedSequence(int n) {
        vi a(2*n-1,-1);
        vi t(2*n-1,-1);
        vi used(n+1);
        dfs(0,2*n-1,n,a,used);

        return a;
    }
};