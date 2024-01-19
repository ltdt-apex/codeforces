import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = inputa()

    ans = 0
    l = 0
    while l < n:
        cur = a[l]
        r = l
        while r < n:
            if a[r] * a[l] < 0:
                break
            cur = max(cur, a[r])
            r+=1

        ans += cur
        l = r
    print(ans)


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1