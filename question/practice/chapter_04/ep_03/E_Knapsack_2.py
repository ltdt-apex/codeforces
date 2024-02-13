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
    n,k = inputa()
    a = [inputa() for _ in range(n)]

    ans = [0]+[math.inf for _ in range(sum(v for w,v in a))]

    for (w,v) in a:
        for j in range(len(ans)-1,-1,-1):
            if j-v>=0:
                ans[j] = min(ans[j], ans[j-v]+w)

    for j in range(len(ans)-1,-1,-1):
        if ans[j] <= k:
            print(j)
            break

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1