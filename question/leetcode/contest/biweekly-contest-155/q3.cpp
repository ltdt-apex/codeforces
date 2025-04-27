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


// https://cp-algorithms.com/string/z-function.html
// The Z-function for the string is an array z of length n where the 
// i-th element is equal to the greatest number of characters 
// starting from the position i that coincide with the first characters of s
// i.e. if z[i] = j, this means j is longest option that s[0...j-1] == v[i...i+j-1]

// O(n) in speed, which bruteforce is O(n^2), or even O(n^3)
// O(n) in memory

vector<int> zfunction(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}


class Solution {
    public:
        int countCells(vector<vector<char>>& v, string p) {
            int n = v.size();
            int m = v[0].size();

            string hs = p;
            hs+='#';
            rep(i,0,n){
                rep(j,0,m){
                    hs+=v[i][j];
                }
            }
            string vs = p;
            vs+='#';
            rep(j,0,m){
                rep(i,0,n){
                    vs+=v[i][j];
                }
            }
            
            vi hsp = zfunction(hs);
            vi vsp = zfunction(vs);
            int mm = p.size();

            vvi a1(n, vi(m));
            vvi a2(n, vi(m));

            // for(auto v: hsp){
            //     cout << v << " ";
            // }cout << endl;

            int c = 0;
            rep(i,0,n){
                rep(j,0,m){
                    // cout << hsp[mm+1+i*m+j] << endl;
                    if(hsp[mm+1+i*m+j] == mm) c=mm;
                    if(c) {
                        // cout << "hi" << endl;
                        a1[i][j] = 1;
                        c--;
                    }
                }
            }

            c = 0;
            rep(j,0,m){
                rep(i,0,n){
                    if(vsp[mm+1+j*n+i] == mm) c=mm;
                    if(c) {
                        a2[i][j] = 1;
                        c--;
                    }
                }
            }

            int a = 0;
            rep(i,0,n){
                rep(j,0,m){
                    // cout << a1[i][j] << " ";
                    if(a1[i][j] and a2[i][j])a++;
                }
                // cout << endl;
            }

            return a;
        }
    };