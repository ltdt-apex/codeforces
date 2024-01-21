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
    a = inputs()
    d = defaultdict(list)
    for i in range(n):
        d[a[i]].append(i)

    q = int(input())

    for _ in range(q):
        d2 = defaultdict(int)
        a2 = inputs()

        ans = -1
        for i in range(len(a2)):
            ans = max(ans, d[a2[i]][d2[a2[i]]])
            d2[a2[i]] += 1
        print(ans+1)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1