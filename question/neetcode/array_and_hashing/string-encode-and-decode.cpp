#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_string;

        for(auto s: strs){
            encoded_string += to_string(s.size());
            encoded_string += '#';
            encoded_string += s;
        }

        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded;

        int i = 0;
        while(i<s.size()){
            string string_size;
            while(s[i]!='#'){
                string_size+=s[i];
                i++;
            }
            i++;
            string decode_string;
            for(int j=0;j<stoi(string_size);j++){
                decode_string+=s[i];
                i++;
            }

            decoded.push_back(decode_string);
        }

        return decoded;
    }
};
