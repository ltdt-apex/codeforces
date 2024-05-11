#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> ms;

    MinStack() {
        
    }
    
    void push(int val) {
        int v = INT_MAX;
        if (!ms.empty())
            v = ms.top();
        ms.push(min(v,val));
        s.push(val);
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