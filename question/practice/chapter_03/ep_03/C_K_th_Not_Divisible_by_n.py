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
    n,k = inputa()
    print(k+(k-1)//(n-1))


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1