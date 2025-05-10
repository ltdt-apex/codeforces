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
    long long minSum(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size();
        int n2 = v2.size();

        ll c1 = 0;
        ll c2 = 0;
        ll s1 = 0;
        ll s2 = 0;

        rep(i,0,n1){
            if(v1[i]==0){
                c1=1;
                s1++;
            }
            else{
                s1+=v1[i];
            }
        }
        rep(i,0,n2){
            if(v2[i]==0){
                c2=1;
                s2++;
            }
            else{
                s2+=v2[i];
            }
        }

        if(s1>s2){
            swap(s1,s2);
            swap(c1,c2);
        }

        if(s1==s2) return s1;
        else{
            if(c1==0) return -1;
            else return s2;
        }
    }
};