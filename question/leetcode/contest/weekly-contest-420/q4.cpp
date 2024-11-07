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

vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";
    vector<int> p(n + 2);
    int l = 1, r = 1;
    for(int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));
        while(s[i - p[i]] == s[i + p[i]]) {
            p[i]++;
        }
        if(i + p[i] > r) {
            l = i - p[i], r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

pair<vector<int>, vector<int>> manacher(string& s) {
    int n = s.size();

    string t;
    for(auto c: s) {
        t += string("#") + c;
    }
    auto d_new = manacher_odd(t + "#");

    vector<int> d_odd(n);
    vector<int> d_even(n);

    rep(i,0,n){
        d_odd[i] = d_new[2*i+1]/2;
        d_even[i] = (d_new[2*i]-1)/2;
    }

    return {d_odd, d_even};
}

class Solution {
public:

    void dfs(int u, vvi& adj, string& ns, int& count, string& s, vii& r){
        int cur = count;

        for(auto v: adj[u]){
            dfs(v, adj, ns, count, s, r);
        }

        r[u] = {cur, count};
        count++;
        ns += s[u];
    }

    vector<bool> findAnswer(vector<int>& p, string s) {
        int n = s.size();
        vector<int> ans(n);

        vvi adj(n);
        rep(i,1,n){
            adj[p[i]].pb(i);
        }

        string ns;
        vii ran(n); // start and end range of string for each i in ns
        int count = 0;

        dfs(0, adj, ns, count, s, ran);
        // cout << ns << endl;

        auto [d_odd, d_even] = manacher(ns);

        // rep(i,0,n){
        //     cout << d_odd[i] << " ";
        // }cout << endl;
        // rep(i,0,n){
        //     cout << d_even[i] << " ";
        // }cout << endl;

        rep(i,0,n){
            cout << i << " ";
            auto [l,r] = ran[i];
            // cout << l << " " << r << endl;
            if((r-l+1)%2 == 0){
                // cout << d_even[(r+l+1)/2] << endl;
                ans[i] = d_even[(r+l+1)/2] >= (r-l+1)/2;
            }
            else{
                // cout << d_odd[(r+l)/2] << endl;
                ans[i] = d_odd[(r+l)/2] >= (r-l+2)/2;
            }
        }

        return vector<bool>(all(ans));
    }
};

