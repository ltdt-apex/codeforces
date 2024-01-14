import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    a  = list(input().strip())
    n = len(a)

    n0 = a.count("0")
    n1 = a.count("1")

    ans = math.inf
    c0 = 0
    c1 = 0
    for i in range(n):
        if a[i] == "0":
            c0 += 1
        else:
            c1 += 1
        ans = min(ans, c1+n0-c0)
        ans = min(ans, c0+n1-c1)

    print(ans)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1