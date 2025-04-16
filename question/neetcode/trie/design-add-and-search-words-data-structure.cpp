#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* c[26] = {nullptr};
    bool isEnd;

    TrieNode(){
        isEnd = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();      
    }
    
    void addWord(string word) {
        TrieNode* node = root;

        for(auto ch: word){
            if(not node->c[ch-'a']) node->c[ch-'a'] = new TrieNode();
            node = node->c[ch-'a'];
        }

        node->isEnd = true;
    }
    
    bool search(string word) {
        stack<pair<TrieNode*,int>> s;
        TrieNode* node = root;
        s.push({root,0});

        while(not s.empty()){
            auto [node, i] = s.top(); s.pop();
            char ch = word[i];
            if(i==word.size()){
                if(node->isEnd) return true;
                continue;
            }

            if(ch=='.'){
                for(int j=0;j<26;j++){
                    if(node->c[j]) s.push({node->c[j],i+1});
                }
            }
            else {
                if(not node->c[ch-'a']) continue;
                s.push({node->c[ch-'a'], i+1});
            }
        }

        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */