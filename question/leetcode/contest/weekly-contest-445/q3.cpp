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

const int threshold = pow(10,7);

int C(int n, int k) {
    double res = 1;
    for (int i = 1; i <= k; ++i)
        res = res * (n - k + i) / i;
        if(res>threshold) return threshold;
    return (int)(res + 0.01);
}


class Solution {
    public:
        string smallestPalindrome(string s, int b) {

            int n = s.size();
            int m = n/2;

            vi count(26);
            rep(i,0,m) count[s[i]-'a']++;
            
            // c = total no. of all permutations of palindrome
            // if c > k -> fail, simply return ""
            {
                int n = m;
                ll c = 1;
                rep(i,0,26){
                    c*=C(n,count[i]);
                    n-=count[i];
                    if(c>=b) break;
                }
    
                if(c<b) return "";
            }

            // iterating all possible permutations, 
            // from i=0, starting from j='a'...'z', 
            // find the number of permutation if a[i]==char j

            // if the number of permutation exceed k,
            // meaning that using current j will achieve k-th smallest, 
            // and we can move on to next char 

            // otherwise, current choice of char j is not yet k-th smallest
            // and we need to use latter j as current char, also
            // we need subtract all no. permutation if a[i]==char j

            string a;
            rep(i,0,m){
                rep(j,0,26){
                    if(count[j]==0) continue;
                    ll c = 1;
                    int n = m-i-1;
                    rep(l,0,26){
                        int used = !!(l==j);
                        int k = count[l]-used;
                        c*=C(n, k);
                        n-=k;
                        if(c>=b) break;
                    }

                    if(c<b){
                        b-=c;
                    }
                    else{
                        a+='a'+j;
                        count[j]--;
                        break;
                    }
                }
            }

            
            string ra = a;
            reverse(all(ra));
            
            if(n%2) a+= s[m];
            return a+ra;
        }
    };


