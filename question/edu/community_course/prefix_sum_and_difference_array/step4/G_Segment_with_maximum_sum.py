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

    l,r,ans = 1, 1, a[0]
    a = [0] + list(accumulate(a))

    nl = 0
    # print(a)
    for i in range(1,n+1):
        if a[i] - a[nl] > ans:
            l = nl+1
            r = i
            ans = a[i] - a[nl]
        if a[i] < a[nl]:
            nl = i
        # print(i,l,r,nl)


    print(l,r,ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1