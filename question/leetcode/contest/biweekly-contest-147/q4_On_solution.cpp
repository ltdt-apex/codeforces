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
        long long maxSubarraySum(vector<int>& v) {
            /*
            using the idea from this question:
            https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
            (variation of kadane algorithm)

            for i=0...n-1,
            find the maximum subarray that end at i,

            to do this,
            we keep track of prefix sum of v[0...i], denote in p,
            we keep track of lowest prefix sum, denote in low,

            in the problem of stock market, 
            find the maximum subarray that end at i is just simply 
            p - low,
            but in our case, there is some treak,

            there are multiple possibility,
                1. for the array that without deleting anything, 
                    then max subarray that end at i is just the same as above question,
                    we denote lowest point as low[0],
                    then the ans should be simply as
                    p - low[0]
            
                2. for the array that with delete,
                    we need subtract the deleted number to p,
                    let's say the deleted number is x,
                    and we need to care that we only count 
                    the number of x between the gap of p and low
                    
                    then the answer is,
                    (p - sum of x's between low and p) - low,

                    by arranging the terms,
                    p - (sum of x's between low and p + low),
                    we can consider sum of x's between low and p as punishment terms of low,

                    then we are back to the original question, 
                    but with a different definition of low,

                    for each x, 
                    the lowest prefix sum can be different, 
                    we denote lowest prefix for the case x as low[x].
            
            now we have p, low[0], different low[x].
            we denote gm = min(low[0], low[x]), gm means global minimum
            the answer is just simply
            p - gm
            */
            int n = v.size();

            ll p = 0;
            unordered_map<ll, ll> low;
            ll gm = 0;
            ll a = v[0];

            rep(i,0,n){
                p+=v[i];
                a = max(a, p-gm);

                if(v[i]<0){
                    if(low.count(v[i])) low[v[i]] = min(low[v[i]], low[0]) + v[i];
                    else low[v[i]] = low[0]+v[i];

                    gm = min(gm, low[v[i]]);
                }

                low[0]=min(low[0], p);
                gm = min(gm, low[0]);
            }
            
            return a;
        }
    };