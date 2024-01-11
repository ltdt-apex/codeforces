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

    ap = [0]*n

    ans = 0
    for i in range(n):
        ap[i] += ap[i-1]
        if ap[i] < a[i] - 1:
            ans += a[i] - 1 - ap[i]
        if a[i] > 1:
            if i+2 < n:
                ap[i+2] += 1
            if i+a[i]+1 < n:
                ap[i+a[i]+1] -= 1
        if ap[i] > a[i]-1:
            if i+1 < n:
                ap[i+1] += ap[i] - a[i] + 1
            if i+2 < n:
                ap[i+2] -= ap[i] - a[i] + 1
        print(ap)

    print(ans)
    # print(ap[-1])

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1