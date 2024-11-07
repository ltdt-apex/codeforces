#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int sum;
            int carry;

            sum = a^b;
            carry = (a&b)<<1;

            a = sum;
            b = carry;

            cout << a << " " << b << endl;
        }

        return a;
    }
};