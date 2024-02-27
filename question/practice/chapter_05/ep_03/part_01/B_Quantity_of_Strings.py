import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

mod = 10**9+7

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n,m,k = inputa()

    if k > n or k == 1:
        ans = 1
        for i in range(n):
            ans *= m
            ans %= mod
        print(ans)
        return
    
    if k==n:
        ans = 1
        for i in range(n//2+n%2):
            ans*=m
            ans %= mod
        print(ans)
        return

    
    if k % 2 == 0:
        print(m)
        return
    else:
        ans = 1
        ans *= m
        ans %= mod            
        ans *= m
        ans %= mod
        print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)