#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        /*
        ["2","1","+","3","*"]

        [3]
        */

        stack<int> stack;
        set<string> opers = {"+","-","*","/"};

        for(auto s: tokens){
            if(opers.count(s)){
                int b = stack.top();
                stack.pop();
                int a = stack.top();
                stack.pop();

                if(s=="+") a+=b;
                if(s=="-") a-=b;
                if(s=="*") a*=b;
                if(s=="/") a/=b;

                stack.push(a);
            }
            else{
                stack.push(stoi(s));
            }
        }

        return stack.top();
    }
};