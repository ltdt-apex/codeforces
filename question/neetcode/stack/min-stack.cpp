#include <bits/stdc++.h>
using namespace std;

class MinStack {
    private:
        stack<int> s;
        stack<int> ms;
    public:
        MinStack() {
            
        }
        
        void push(int val) {
            s.push(val);
            if(not ms.empty() and ms.top()<val){
                ms.push(ms.top());
            }
            else{
                ms.push(val);
            }
        }
        
        void pop() {
            s.pop();
            ms.pop();
        }
        
        int top() {
            return s.top();
        }
        
        int getMin() {
            return ms.top();
        }
    };
    

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */