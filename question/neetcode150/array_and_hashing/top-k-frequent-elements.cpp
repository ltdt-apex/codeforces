#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
 
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll,ll>> vll;
typedef vector<vector<pair<ll,ll>>> vvll;
typedef vector<vector<vector<ll>>> vvvl;
typedef vector<tuple<ll, ll, ll>> vlll;
 
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
#define ceild(a,b) (a)%(b) ? ((a)/(b) + 1) : (a)/(b)
#define TxtIO freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
 
const ll mod = 1e9 + 7;
 
const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;
 
const int lt = 32;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int, int> d;
        for (auto n:a){
            d[n]++;
        }

        vector<vector<int>> count(a.size()+1);

        for (auto [k,v]: d){
            count[v].pb(k);
        }

        vector<int> ans;

        repr(i,count.size()-1,-1){
            ans.insert(ans.end(), all(count[i]));
            if (ans.size()==k)
            break;
        }

        return ans;
    }
};