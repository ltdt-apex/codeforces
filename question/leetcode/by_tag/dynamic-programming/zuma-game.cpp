// @prefix template
// @description 

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

const int au = 65;
const int al = 97;
const int zu = 90;
const int zl = 122;

const int lt = 32;

class Solution {
public:
    unordered_map<string, int> map;

    int findMinStep(string v, string h) {
        // TLE, maybe there is better time complexity approach, 
        // otherwise, it's just clever bruteforce optimizing 
        ll n = v.size();
        ll m = h.size();
        sort(all(h));

        string key = v+'#'+h;
        if(map.count(key)) return map[key];
        if(n==0) return 0;
        if(m==0) return -1;

        int a = INT_MAX;
        
        unordered_set<char> used;
        rep(i,0,m){
            char u = h[i];
            if(used.count(u)) continue;
            used.insert(u);

            string y;
            rep(j,0,m){
                if(i!=j) y+=h[j];
            }

            rep(j,0,n+1){
                string x;
                rep(k,0,j) x += v[k];
                x+=u;
                rep(k,j,n) x += v[k];

                int l = j;
                int r = j;
                int k = 0;

                while(l>=0 and r<n+1 and x[l]==x[r]){
                    int ll = l;
                    int rr = r;
                    char c = x[l];
                    while(ll-1>=0 and x[ll-1]==c) ll--;
                    while(rr+1<n+1 and x[rr+1]==c) rr++;
                    if(rr-ll+1-k<3) break;

                    l = ll-1;
                    r = rr+1;
                    k = rr-ll+1;
                }

                if(l==r){
                    int s = findMinStep(x,y);
                    if(s != -1) a = min(a, 1+s);
                    // cout << x << " " << y << endl;
                }
                else{
                    string ns;
                    rep(c,0,l+1) ns+=x[c];
                    rep(c,r,n+1) ns+=x[c];

                    int s = findMinStep(ns,y);
                    if(s != -1) a = min(a, 1+s);
                    // cout << ns << " " << y << endl;
                }
            }
        }
        if(a==INT_MAX) a = -1;
        map[key] = a;

        return a;
    }
};