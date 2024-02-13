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
    n,m,c,d = inputa()
    a = [inputa() for _ in range(m)]

    ans = [0] * (n+1)

    for i in range(n//c+1):
        ans[c*i] = d*i

    for w,wd,wc,v in a:
        for k in range(n,-1,-1):
            for j in range(1,w//wd+1):
                if k-wc*j >= 0:
                    ans[k] = max(ans[k], ans[k-wc*j] + j*v)
        
    print(max(ans))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1