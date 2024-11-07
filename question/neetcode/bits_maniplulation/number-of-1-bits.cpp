#include <bits/stdc++.h>

using namespace std;

/*
5 (101)
5%2
5/2 = 3

until 0
count n%2

1 (1) -> 0
2 (10) -> 1
3 (11) -> 1
4 (100) -> 2
5 (101) -> 2
6 (110) -> 3
*/

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n){
            if(n%2) count++;
            n/=2;
        }

        return count;
    }
};