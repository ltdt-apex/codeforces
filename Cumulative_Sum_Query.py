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
    a = list(accumulate(a))

    for i in range(q):
        l,r = inputa()
        if l == 0:
            print(a[r])
        else:
            print(a[r]-a[l-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1