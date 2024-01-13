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

    q = int(input())
    qs = [inputa() for i in range(q)]

    a = [0] + list(accumulate(a))

    for l,r in qs:
        l-=1
        print(a[r]-a[l])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1