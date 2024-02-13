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

def solve():
    n = int(input())
    k = (1+n)*n//2

    if k%2==1:
        print(0)
        return
    
    k//=2

    ans = [1]+[0]*k

    for i in range(1,n+1):
        for j in range(k,-1,-1):
            if j-i>=0:
                ans[j] = ans[j]%mod + ans[j-i] % mod

    print(ans[-1]//2)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1