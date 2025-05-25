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
        vector<int> pathExistenceQueries(int n, vector<int>& val, int d, vector<vector<int>>& qs) {
            vii s;
            int m = qs.size();

            rep(i,0,n){
                s.pb({val[i],i});
            }
            sort(all(s));
            
            viii qsi(m);
            rep(i,0,m){
                int u = qs[i][0];
                int v = qs[i][1];

                if(val[u] > val[v]) swap(u,v);
                qsi[i] = {u,v,i};
            }
            
            sort(all(qsi), [&](auto a, auto b){
                // sort order too?
                int aa,ab,ac;
                int ba,bb,bc;
                tie(aa,ab,ac) = a;
                tie(ba,bb,bc) = b;
                if(aa==ba) return val[ab] < val[bb];
                return val[aa] < val[ba];
            });

            vi dist(n, -1);
            set<pii> dists;

            int cur = -1;
            int dis = 0;
            int fp = 0;
            int cv = 0;
            int cu = 0;
            int delta = 0;
            int deltav = 0;
            int mv = -1;
            vi ans(m, -1);
            rep(i,0,m){
                // for(auto x: val){
                //     cout << x << ' ';
                // }cout << endl;
                int u,v,ai;
                tie(u,v,ai) = qsi[i];
                if(cur!=u){
                    cur = u;
                    delta = 0;
                    deltav = INT_MAX;
                    fp = 0;
                }
                dis = 0;
                cv = val[u];
                cu = u;
                mv = max(cv,mv);

                int vv = val[v];
                
                cout << u << " " << v << endl;
                cout << cv << " " << vv << endl;
                // cout << mv << endl;
                // cout << endl;

                if(u==v){
                    ans[ai] = 0;
                    continue;
                }

                if(vv==val[u]){
                    ans[ai] = 1;
                    continue;
                }

                while(fp==0){
                    dis++;
                    auto it = lower_bound(all(s), mp(cv+d+1,-1));
                    it = prev(it);
                    auto [nv, nu] = *it;
                    // cout << nv << " " << ans[ai] << " " << dis << endl;
                    // if(vv<=nv and ans[ai]==-1){
                        // ans[ai] = dis;
                        // cout << ans[ai]<< endl;
                    // }
                    // cout << nv << endl;
                    // auto ni = it - s.begin();
                    if(nu==cu) {
                        break;
                    }

                    cv = nv;
                    // ci = ni;
                    // cout << ni << endl;
                    cu = nu;
                    mv = max(cv,mv);
                    if(dist[cu]!=-1){
                        fp = 1;
                        // cout << "diff:" << cu << " " << dist[cu] << ' ' << dis << endl;
                        delta = dist[cu] - dis;
                        deltav = cv;
                        break;
                    }
                    dist[cu] = dis;
                    dists.insert({nv, dis});
                }

                if(ans[ai]!=-1) continue;
                if(mv<vv) ans[ai] = -1;
                else{
                    auto [vvv,d] = *lower_bound(all(dists), mp(vv,-1));
                    cout << "vv:" << vvv << " " <<  d << " " << delta << endl;
                    if(vvv<deltav)ans[ai] = d;
                    else ans[ai] = d-delta;
                }

                // cout << endl;
            }
            

            return ans;
        }
    };
