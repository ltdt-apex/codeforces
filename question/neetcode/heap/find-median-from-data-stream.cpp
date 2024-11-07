#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> lowerhalf;
    priority_queue<int, vector<int>, greater<int>> upperhalf;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        if(lowerhalf.empty() or upperhalf.empty()){
            lowerhalf.push(num);
        }
        else {
            if(num < lowerhalf.top()){
                lowerhalf.push(num);
            }else{
                upperhalf.push(num);
            }
        }

        if(lowerhalf.size() > upperhalf.size()+1){
            upperhalf.push(lowerhalf.top());
            lowerhalf.pop();
        }
        if(upperhalf.size() > lowerhalf.size()+1){
            lowerhalf.push(upperhalf.top());
            upperhalf.pop();
        }
    }
    
    double findMedian() {
        if(lowerhalf.size() == upperhalf.size()){
            return (double)((lowerhalf.top() + upperhalf.top())/2.0);
        }
        else if(lowerhalf.size() > upperhalf.size()){
            return lowerhalf.top();
        }else{
            return upperhalf.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */