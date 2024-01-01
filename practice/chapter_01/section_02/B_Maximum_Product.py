import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
import math
from math import prod

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    ans = -math.inf

    ans = max(ans, prod(a[n-5:]))
    ans = max(ans, prod(a[0:2] + a[n-3:]))
    ans = max(ans, prod(a[0:4] + a[n-1:]))
    print(ans)


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1