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

void solve(int TC) {
    // dp[i][j] = query i, if hand is left, j = min step for right hand to position j.
    // if hand is right, j = min step for left hand to position j.


    // ll n;
    // cin >> n;

    int n,q;
    cin >> n >> q;

    vector<pair<char, ll>> qs(q);

    rep(i,0,q){
        cin >> qs[i].f >> qs[i].s;
        qs[i].s--;
    }

    vl dp(n,LONG_LONG_MAX);
    dp[0] = 0;
    ll last = 1;
    char lh = 'R';


    for(auto [h,p]: qs){
        vl ndp(n,LONG_LONG_MAX);

        rep(i,0,n){
            if(dp[i] == LONG_LONG_MAX) continue;

            // same hand as previous queries
            if((h=='L' and lh=='L') or (h=='R' and lh=='R')){
                // move clockwise
                int j = i;
                int t = p;
                if(j<last) j+=n;
                if(t<last) t+=n;
                if(j<=t){
                    // blocked case
                    ndp[(p+1)%n] = min(ndp[(p+1)%n], dp[i] + t-last + t+1-j);
                }else{
                    // no blocked case
                    ndp[i] = min(ndp[i], dp[i]+t-last);
                }

                // move counterclockwise
                j=i;
                t=p;
                if(j>last) j-=n;
                if(t>last) t-=n;
                if(j>=t){
                    // blocked case
                    ndp[(p-1+n)%n] = min(ndp[(p-1+n)%n], dp[i] + last-t + j-(t-1));
                }else{
                    // no blocked case
                    ndp[i] = min(ndp[i], dp[i]+last-t);
                }
            }

            // not same hand as previous queries
            else{
                // move clockwise
                int j = last;
                int t = p;
                if(j<i) j+=n;
                if(t<i) t+=n;
                if(j<=t){
                    // blocked case
                    ndp[(p+1)%n] = min(ndp[(p+1)%n], dp[i] + t-i + t+1-j);
                }else{
                    // no blocked case
                    ndp[last] = min(ndp[last], dp[i]+t-i);
                }

                // move counterclockwise
                j=last;
                t=p;
                if(j>i) j-=n;
                if(t>i) t-=n;
                if(j>=t){
                    // blocked case
                    ndp[(p-1+n)%n] = min(ndp[(p-1+n)%n], dp[i] + i-t + j-(t-1));
                }else{
                    // no blocked case
                    ndp[last] = min(ndp[last], dp[i]+i-t);
                }
            }
        }

        last = p;
        lh = h;
        dp = ndp;

        // rep(i,0,n){
        //     if(dp[i] == LONG_LONG_MAX) cout << -1 << " ";
        //     else cout << dp[i] << " ";
        // }cout << endl;
    }

    ll ans = *min_element(all(dp));
    if(ans == LONG_LONG_MAX){
        cout << -1;
        return;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve(TC);
    }
}

