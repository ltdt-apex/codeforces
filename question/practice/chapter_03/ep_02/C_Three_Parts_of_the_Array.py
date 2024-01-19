import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve():
    n = int(input())
    a = inputa()

    l,r,ans = 0,n-1,0
    ls, rs = 0,0

    while l <= r:
        if ls < rs:
            ls+=a[l]
            l+=1
        else:
            rs+=a[r]
            r-=1
        if ls == rs:
            ans = ls
            
    print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1