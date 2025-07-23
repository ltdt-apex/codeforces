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
    long long minimumDifference(vector<int>& v) {
        int n = v.size();

        vl pre(n);
        priority_queue<ll> qPre;
        vl post(n);
        priority_queue<ll, vl, greater<ll>> qPost;

        ll s = 0;
        rep(i,0,n){
            s+=v[i];
            qPre.push(v[i]);

            // cout << qPre.top() << " ";
            if(i>=n/3) s-=qPre.top(), qPre.pop();
            pre[i] = s;
        }
            // cout << endl;

        s = 0;
        repr(i,n-1,-1){
            s+=v[i];
            qPost.push(v[i]);
            
            if(i<=n/3*2-1) s-=qPost.top(), qPost.pop();
            post[i] = s;
        }

        // for(auto x: pre){
        //     cout << x << " ";
        // }cout << endl;
        // for(auto x: post){
        //     cout << x << " ";
        // }cout << endl;

        ll m = LONG_LONG_MAX;
        rep(i,n/3,n/3*2+1){
            // cout << i << " " << pre[i-1] << " " << post[i] << endl;
            m = min(m,pre[i-1]-post[i]);
        }

        return m;
    }
};