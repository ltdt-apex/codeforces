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
    int minLength(string s, int m) {
        int n = s.size();

        int j = n;
        int k = n;

        auto ok = [&](int j){
            if(j==1){
                int c1 = 0;
                int c2 = 0;
                rep(i,0,n){
                    if(i%2!=s[i]-'0')c1++;
                    if(i%2==s[i]-'0')c2++;

                }
                // cout << c1 << " " << c2 << endl;
                return min(c1,c2)<=m;
            }

            char l = s[0];
            int c = 0;
            int a = 0;
            rep(i,0,n){
                if(s[i]==l){
                    c++;
                    if(c>j){
                        a++;
                        if(i+1<n){
                            l = s[i+1];
                        }
                        c=0;
                    }
                }
                else{
                    l = s[i];
                    c=1;
                }
            }

            // cout << j << " " << a << endl;

            return a<=m;
        };

        while(k){
            while(j-k>=1 and ok(j-k))j-=k;
            k/=2;
        }

        return j;
        
    }
};
