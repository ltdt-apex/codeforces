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

unordered_map<int,int> findPrimes(int x){
    unordered_map<int,int> c;
 
    for(int i=2;i*i<=x;i++){
        while(x%i==0){
            c[i]++;
            x/=i;
        }
    }
 
    if(x>=2){
        c[x]++;
    }
 
    return c;
}

class Solution {
public:
    long long maxGCDScore(vector<int>& v, int k) {
        ll a = 0;
        int n = v.size();

        vi c2(n);

        rep(i,0,n){
            unordered_map<int,int> ps = findPrimes(v[i]);

            c2[i] = ps[2];
        }
        
        rep(i,0,n){
            ll c = 0;
            ll m = c2[i];
            ll x = v[i];

            repr(j,i,-1){
                if(c2[j]<m){
                    c=1;
                    m=c2[j];
                }
                else if(c2[j]==m) c++;
                x = gcd(x,v[j]);

                if(c<=k) a = max(a,x*2*(i-j+1));
                else a = max(a,x*(i-j+1));
            }
        }

        return a;
    }
};

