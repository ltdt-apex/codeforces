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
    int maxCandies(vector<int>& ss, vector<int>& cs, vector<vector<int>>& ks, vector<vector<int>>& bs, vector<int>& v) {
        queue<int> q;
        unordered_set<int> sb;
        unordered_set<int> sk;
        for(auto x: v){
            if(ss[x]==0) sb.insert(x);
            else q.push(x);
        }

        int a = 0;
        while(not q.empty()){
            auto x = q.front(); q.pop();
            cout << x << endl;

            a+=cs[x];

            for(auto k: ks[x]){
                sk.insert(k);
                if(sb.count(k)){
                    q.push(k);
                    sb.erase(k);
                }
            }
            for(auto b: bs[x]){
                if(ss[b]==0 and not sk.count(b)) sb.insert(b);
                else q.push(b);
            }

        }

        return a;
    }
};