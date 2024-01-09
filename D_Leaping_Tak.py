import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,k = inputa()
    ks = [inputa() for i in range(k)]

    a = [0] * n
    a[0] += 1
    a[1] -= 1

    for i in range(n):
        if i-1 >= 0:
            a[i] += a[i-1]
            a[i] %= 998244353
        for l,r in ks:
            if i+l < n:
                a[i+l] += a[i]
            if i+r+1 < n:
                a[i+r+1] -= a[i]

    print(a[-1]%998244353)



if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1