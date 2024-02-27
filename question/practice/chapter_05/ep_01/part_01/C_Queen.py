import sys
# sys.setrecursionlimit(10**5+10000)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n = int(input())
    a = [inputa() for _ in range(n)]

    d = [1]*n

    for i, (p,v) in enumerate(a):
        if v==0:
            d[i] = 0
            if p!=-1:
                d[p-1] = 0

    if any(d):
        print(*[i+1 for i in range(n) if d[i]])
    else:
        print(-1)



if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)