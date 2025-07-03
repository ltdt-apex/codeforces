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
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vi c(26);

        rep(i,0,n){
            c[s[i]-'a']++;
        }

        vi vc;

        repr(i,25,-1){
            if(c[i]>=k) vc.pb(i);
        }

        queue<string> q;
        for(auto c: vc){
            q.push(string(1,c+'a'));
        }

        string a;

        auto valid = [&](string& cs){
            int m = cs.size();
            int j = 0;
            int count = 0;

            rep(i,0,n){
                if(cs[j]==s[i]){
                    j++;
                    if(j==m){
                        count++;
                        j=0;
                    }

                    if(count==k) return 1;
                }
            }

            return 0;
        };

        while(not q.empty()){
            string cs = q.front(); q.pop();
            if(cs.size()>a.size() or (cs.size()==a.size() and cs>a)) a = cs;
            // if(cs.size()==7) continue;

            for(auto c: vc){
                string ns = cs;
                ns+=c+'a';
                // cout << ns << endl;

                if(valid(ns)){
                    // cout << "valid: " << ns << endl;
                    q.push(ns);
                }
            }
        }

        return a;
    }
};