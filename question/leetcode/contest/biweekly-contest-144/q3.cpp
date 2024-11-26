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

class Solution {
public:
    int maxRemoval(vector<int>& v, vector<vector<int>>& qs) {
        sort(all(qs));

        int n = v.size();
        int m = qs.size();
        priority_queue<int> qa;
        priority_queue<int, vi, greater<int>> qu;

        int j = 0;
        int a = 0;

        rep(r,0,n){
            while(j<m and qs[j][0]==r){
                qa.push(qs[j][1]);
                j++;
            }

            while(not qu.empty() and qu.top()<r){
                qu.pop();
            }

            while(qu.size() < v[r] and not qa.empty() and qa.top()>=r){
                qu.push(qa.top());
                qa.pop();
                a++;
            }


            if(qu.size()<v[r]){
                return -1;
            }
        }

        return m-a;
    }
};

