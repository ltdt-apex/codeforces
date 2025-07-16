#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string word) {
        if(word.size()<3) return false;
        bool haveVowel = false;
        bool haveConsonant = false;

        unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};

        for(char w: word){
            if(w>='0' and w<='9') continue;
            else if((w>='a' and w<='z') or (w>='A' and w<='Z')){
                if(w>='A' and w<='Z') w = w-'A'+'a';

                if(vowel.count(w)) haveVowel = true;
                else haveConsonant = true;
            }
            else{
                return false;
            }
        }

        return haveVowel and haveConsonant;
    }
};