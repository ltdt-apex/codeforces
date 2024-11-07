#include <bits/stdc++.h>

using namespace std;

/*
abc
abd
add
   100*100
a [b,d] -> b [c,d] -> c
                 -> d
        -> d [d] -> d

*/

struct TrieNode{
    vector<char> order;
    TrieNode* child[26] = {nullptr};

    TrieNode() {}
};

struct Trie{
    TrieNode* root;

    Trie(){
        root = new TrieNode();
    }

    bool insert(string& word, vector<unordered_set<int>>& adj){
        TrieNode* node = root;
        for(char c: word){
            int x = c - 'a';
            for(auto pre: node->order){
                if(pre==x) continue;
                adj[pre].insert(x);
            }
            node->order.push_back(x);
            if(not node->child[x]) node->child[x] = new TrieNode();
            node = node->child[x];
        }

        for(int i=0;i<26;i++){
            if (node->child[i]) return false;
        }
        return true;
    }
};

class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        Trie trie = Trie();
        vector<unordered_set<int>> adj(26);

        for(auto& word: words){
            if(not trie.insert(word, adj)) return "";
        }

        vector<int> count(26);
        vector<int> required(26);
        queue<int> q;
        string ans;

        for(int from=0;from<26;from++){
            for(auto to: adj[from]){
                required[to]++;
            }
        }

        for (int i=0;i<26;i++){
            if(required[i]==0){
                q.push(i);
            }
        }

        while(not q.empty()){
            int from = q.front();
            ans += from+'a';
            q.pop();

            for(auto to: adj[from]){
                count[to]++;
                if(count[to] == required[to]){
                    q.push(to);
                }
            }
        }

        if(ans.size()==26) return ans;
        else return "";
    }
};
