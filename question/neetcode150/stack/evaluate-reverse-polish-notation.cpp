#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    bool isNumeric(const std::string& str) {
        try {
            stoi(str);
            return true;
        } catch (...) {
            return false;
        }
    }

    int evalRPN(vector<string>& ss) {
        stack<int> s;

        for (auto x: ss){
            if(isNumeric(x)){
                s.push(stoi(x));
            }
            else{
                int y,z;
                z = s.top();
                s.pop();
                y = s.top();
                s.pop();

                if (x == "+"){
                    s.push(y+z);
                }
                if (x == "-"){
                    s.push(y-z);
                }
                if (x == "*"){
                    s.push(y*z);
                }
                if (x == "/"){
                    s.push(y/z);
                }
            }
        }

        return s.top();
    }
};