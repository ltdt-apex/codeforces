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

int isPrime(int x){
    if(x==1) return 0;

    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
 
    return 1;
}

class Solution {
public:
    int primeSubarray(vector<int>& v, int k) {
        ll a = 0;

        int n = v.size();

        multiset<int> sl;
        multiset<int> sr;

        int l = 0;
        int r = 0;

        rep(i,0,n){
            if(isPrime(v[i])){
                sl.insert(v[i]);
                sr.insert(v[i]);
            }

            while(sl.size()>=2){
                int mi = *sl.begin();
                int ma = *prev(sl.end());

                if(ma-mi<=k) break;
                if(isPrime(v[l])) sl.erase(sl.find(v[l]));
                l++;
            }

            while(sr.size()>=2){
                if(sr.size()==2 and sr.count(v[r])) break;

                if(isPrime(v[r])) sr.erase(sr.find(v[r]));
                r++;
            }

            // cout << i << " " << r-l+1 << endl;

            if(sr.size()>=2){
                // cout << i << " " << r-l+1 << endl;

                a+=r-l+1;
            }
        }

        return a;
    }
};

