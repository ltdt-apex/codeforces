#include <bits/stdc++.h>
using namespace std;

struct Point{
    long long d;
    int x;
    int y;

    Point(long long d, int x, int y): d(d), x(x), y(y){

    };


    bool operator>(const Point& other) const{
        return d > other.d;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<Point, vector<Point>, greater<Point>> q;

        for(auto p: points){
            q.push(Point((long long)p[0]*p[0]+(long long)p[1] * p[1], p[0], p[1]));
        }

        vector<vector<int>> ans;

        for(int i=0;i<k;i++){
            Point p = q.top(); q.pop();
            ans.push_back({p.x, p.y});
        }

        return ans;
    }
};