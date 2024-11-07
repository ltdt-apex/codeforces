#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* child[26] = {nullptr};
    bool isEnd = false;

    TrieNode(){}
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;

        for(auto c: word){
            if(not cur->child[c-'a']) cur->child[c-'a'] = new TrieNode();
            cur = cur->child[c-'a'];
        }

        cur->isEnd = true;
    }
    
    bool search(string word) {
        stack<pair<int, TrieNode*>> s;
        s.push({0, root});

        bool found = false;

        while(not s.empty()){
            bool currentVaild = true;

            auto [i, cur] = s.top();
            s.pop();
            for(int j = i; j<word.size(); j++){
                char c = word[j];
                if (c=='.'){
                    for(auto ch: cur->child){
                        if(ch) s.push({j+1,ch});
                    }
                    currentVaild = false;
                    break;
                }
                else if(not cur->child[c-'a']){
                    currentVaild = false;
                    break;
                };
                cur = cur->child[c-'a'];
            }
            if(currentVaild) found |= cur->isEnd;
        }

        return found;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */