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
    a = inputa()

    a.sort()

    m = n//2
    c = 1

    for i in range(m, n):
        # print(i,k)
        if i + 1 < n:
            if k >= c*(a[i+1] - a[i]):
                k-=c*(a[i+1] - a[i])
                c+=1
            else:
                print(a[i] + k//c)
                return
        else:
            print(a[i] + k//c)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1