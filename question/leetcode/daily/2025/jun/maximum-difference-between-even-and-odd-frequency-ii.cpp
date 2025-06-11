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
    int maxDifference(string s, int k) {
        /*
        fixed two numbers a,b
        we use two pointer method to find max of freq[a] - freq[b]

        for right pointer, we advance right pointer by one each time,
        for each right pointer, we want to find max of freq[a] - freq[b],
            for subarray ending in right pointer
        
        now we are looking for,
        max of (freqr[a] - freql[a]) - (freqr[b] - freql[b]), for any left pointer
        = freqr[a] - freqr[b] - min of (freql[a] - freql[b]), for any left pointer

        in here, based on question restriction, we need to make sure 
        (freqr[a] - freql[a]) is odd, and 
        (freqr[b] - freql[b]) is even
        
        so we keep track of four state of minimum of (freql[a] - freql[b])
        1. odd a and odd b
        2. odd a and even b
        3. even a and odd b
        4. even a and even b

        based on the state of right pointer, we interact with the corresponding state of left pointer,
        which make (freqr[a] - freql[a]) is odd, and (freqr[b] - freql[b]) is even.
            that is, because of 
                same parity difference = even
                opposite parity difference = odd,
            we lookup with the state of left pointer that have 
                opposite parity of a, and 
                same parity of b to right pointer

        with this four state, it can help us find
            freqr[a] - freqr[b] - min of (freql[a] - freql[b]) in O(1)

        also, we only advance left pointer and update state based on question restriction,
            1. the subarray has size at least k
            2. char a have freq >= 1
            3. char b have freq >= 2
        */

        int n = s.size();
        int a = -INT_MAX;

        rep(i,0,5){
            rep(j,0,5){
                if(i==j) continue;

                // cout << "ind: " << i << " " << j << endl;

                vi pi(n+1);
                vi pj(n+1);
                rep(l,0,n){
                    pi[l+1] = pi[l]+(s[l]==('0'+i));
                    pj[l+1] = pj[l]+(s[l]==('0'+j));
                }

                // rep(i,1,n+1){
                //     cout << pi[i] << " ";
                // }cout << endl;
                // rep(i,1,n+1){
                //     cout << pj[i] << " ";
                // }cout << endl;

                int l = 0;
                vvi ps = {{INT_MAX, INT_MAX}, {INT_MAX, INT_MAX}};

                rep(r,1,n+1){
                    // cout << r << endl;
                    while(r-l>=k and pi[r]-pi[l]>=1 and pj[r]-pj[l]>=2){
                        int pari = pi[l]%2;
                        int parj = pj[l]%2;
                        // cout << pari << ' ' << parj << " " << pi[l]-pj[l] << " " << endl;

                        ps[pari][parj] = min(ps[pari][parj], pi[l]-pj[l]);
                        l++;
                    }
                    
                    int pari = pi[r]%2;   
                    int parj = pj[r]%2;

                    if(ps[1-pari][parj]!=INT_MAX){
                        a = max(a,pi[r]-pj[r]-ps[1-pari][parj]);
                    }

                    // rep(b,0,2){
                    //     rep(c,0,2){
                    //         cout << ps[b][c] << " ";
                    //     }cout << endl;
                    // }cout << endl;
                }
            }
        }

        return a;
    }
};