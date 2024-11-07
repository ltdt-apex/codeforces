#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26] = {nullptr};
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;

        for(auto c: word){
            if (not cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;

        for(auto c: word){
            if (not cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }

        return cur->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;

        for(auto c: prefix){
            if (not cur->child[c-'a']) return false;
            cur = cur->child[c-'a'];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */