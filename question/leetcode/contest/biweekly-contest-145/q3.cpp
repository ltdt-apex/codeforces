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

int isprime(int x){
    if(x==1) return 0;

    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }

    return 1;
}

class Solution {
public:
    int minOperations(int n, int m) {
        if(isprime(n)) return -1;

        // unordered_set<int> p;
        // rep(i,1,pow(10,4)+2){
        //     if(isprime(i)){
        //         p.insert(i);
        //     }
        // }

        priority_queue<pii, vii, greater<pii>> q;
        q.push({n,n});

        vi dist(pow(10,4)+2, INT_MAX);

        while(not q.empty()){
            auto [d,x] = q.top();
            // cout << "x: " << x << endl;
            q.pop();

            if(x == m) return d;

            int r = x;
            int pow = 1;
            while(r){
                int dx = r%10;

                if(dx>0){
                    int nx = x-pow;
                    if((not isprime(nx)) and d+nx < dist[nx]){
                        q.push({d+nx, nx});
                        dist[nx] = d+nx;
                    }
                }
                if(dx<9){
                    int nx = x+pow;
                    if((not isprime(nx)) and d+nx < dist[nx]){
                        q.push({d+nx, nx});
                        dist[nx] = d+nx;
                    }
                }

                r/=10;
                pow*=10;
            }            
        }

        return -1;
    }
};
