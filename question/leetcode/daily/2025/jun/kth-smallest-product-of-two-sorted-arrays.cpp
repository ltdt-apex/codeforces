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
    long long kthSmallestProduct(vector<int>& v1, vector<int>& v2, long long k) {
        int n1 = v1.size();
        int n2 = v2.size();

        ll l = -pow(10,9)-5;
        ll r = pow(10,9)+5;

        auto f = [&](ll m){
            // cout << m << endl;
            ll c = 0;
            int p2 = 0;
            int fp = 0;

            rep(p1,0,n1){
                if(v1[p1]<0){
                    while(p2<n2 and (ll)v1[p1]*v2[p2]>m) p2++;
                    c+=n2-p2;
                }
                else if(v1[p1]==0){
                    if(m>=0) c+=n2;
                }
                else{
                    if(not fp){
                        fp=1;
                        p2=n2-1;
                    }
                    // cout << p1 << " " << p2 << endl;
                    while(p2>=0 and (ll)v1[p1]*v2[p2]>m) p2--;
                    // cout << p1 << " " << p2 << endl;
                    c+=p2+1;
                }

                cout << p1 << " " << c << endl;
            }

            return c;
        };

        while(l+1<r){
            ll mid = (l+r)/2;
            // if(l==r-1)mid = l+1;
            
            ll n = f(mid);
            cout << l << " " << r << " " << mid << " " << n << endl;

            if(n>=k) {
                r = mid;
            }
            else {
                l = mid+1;
            }
        }

        if(f(l)==k) return l;
        else return r;
    }
};