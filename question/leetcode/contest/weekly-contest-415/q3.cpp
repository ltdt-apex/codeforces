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


// Trie 
// O(n) insert, search, startwiths
// O(n) in memory

struct TrieNode {
    TrieNode* c[26] = {nullptr};
    int isEndOfWord;

    TrieNode() : isEndOfWord(0) {}
};

struct Trie {
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (not current->c[ch-'a']) {
                current->c[ch-'a'] = new TrieNode();
            }
            current = current->c[ch-'a'];
        }
        current->isEndOfWord = 1;
    }

    // Search for a word in the Trie
    int search(const std::string& word) {
        TrieNode* current = root;
        for (char ch : word) {
            if (not current->c[ch-'a']) {
                return 0;
            }
            current = current->c[ch-'a'];
        }
        return current->isEndOfWord;
    }

    // Check if any word in the Trie starts with the given prefix
    int startsWith(const std::string& prefix) {
        TrieNode* current = root;
        for (char ch : prefix) {
            if (not current->c[ch-'a']) {
                return 0;
            }
            current = current->c[ch-'a'];
        }
        return 1;
    }
};

class Solution {
public:
    int minValidStrings(vector<string>& v, string a) {
        Trie t;

        for(auto& w: v){
            t.insert(w);
        }

        ll n = a.size();

        vl dp(n+1, INT_MAX);
        dp[0] = 0;

        rep(i,0,n){
            TrieNode* node = t.root;
            rep(j,i,n){
                if(not node->c[a[j]-'a']) break;
                node = node->c[a[j]-'a'];
                dp[j+1] = min(dp[j+1], dp[i]+1);
            }
        }

        return dp.back()==INT_MAX ? -1 : dp.back();
    }
};