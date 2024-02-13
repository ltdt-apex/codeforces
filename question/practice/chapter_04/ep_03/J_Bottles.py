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
    b = inputa()
    min_ = sum(a)
    t = sum(b)

    ans = [[math.inf]*(t+1) for _ in range(n+1)]
    ans[-1][-1] = 0

    # print(len(ans), len(ans[0]))

    for v,c in zip(a,b):
        for i in range(n+1):
            for j in range(min_, t+1):
                if j+c <= t and i+1 <= n:
                    ans[i][j] = min(ans[i][j], ans[i+1][j+c] + v)

    # print(ans)

    for i in range(n+1):
        v = None
        m = math.inf
        for j in range(min_, t+1):
            if ans[i][j] < m:
                m = ans[i][j]
                v = i
        if v:
            print(v, m)
            return


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1