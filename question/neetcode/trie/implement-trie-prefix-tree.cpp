#include <bits/stdc++.h>
using namespace std;

struct TrieNode{
    TrieNode* c[26] = {nullptr};
    bool isEnd = false;
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
            TrieNode* node = root;
            int n = word.size();

            queue<pair<TrieNode*, int>> q;
            q.push({node, 0});

            while(not q.empty()){
                auto [node, i] = q.front(); q.pop();
                if(i==n) 
                    if(node->isEnd) return true;
                else
                    continue;

                char ch = word[i];
                if(ch=='.'){
                    for(int j=0;j<26;j++){
                        if(not node->c[j]) continue;
                        q.push({node->c[j], i+1});
                    }
                }
                else{
                    if(not node->c[ch-'a']) continue;
                    q.push({node->c[ch-'a'], i+1});
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