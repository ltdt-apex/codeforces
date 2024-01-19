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

    l = 0
    r = n-1
    i = 0
    ans = [0,0]
    while l <= r:
        if a[l] > a[r]:
            ans[i] += a[l]
            l+=1
        else:
            ans[i] += a[r]
            r-=1
        i = (i+1)%2

    print(*ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1