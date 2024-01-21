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
    q = int(input())
    a.sort()

    for _ in range(q):
        x = int(input())

        k = n
        ans = -1
        while k >= 1:
            while ans+k < n and a[ans+k] <= x:
                ans+=k
            k//=2

        print(ans+1)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1