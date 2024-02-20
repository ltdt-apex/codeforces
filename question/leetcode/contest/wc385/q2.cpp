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
    string lastNonEmptyString(string s) {
        unordered_map<char, int> d;
        unordered_map<char, int> d2;

        for (auto c: s){
            d[c]++;
        }

        int m = 0;

        string ans;

        auto x = (*max_element(d.begin(), d.end(), [](auto p1, auto p2){return p1.s < p2.s;})).s;

        for (auto c:s){
            d2[c]++;
            if (d2[c] == x){
                ans+=c;
            }
        }

        return ans;
    }
};