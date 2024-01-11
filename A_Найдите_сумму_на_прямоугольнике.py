import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def prefix_2d(a):
    from itertools import accumulate
    
    return list(list(a) for a in zip(*map(accumulate, zip(*map(accumulate, a)))))

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m = inputa()
    a = [inputa() for i in range(n)]

    q = int(input())
    qs = [inputa() for i in range(q)]

    a = prefix_2d(a)
    for i in range(n):
        a[i].insert(0, 0)
    a.insert(0, [0]*(m+1))

    for t,l,d,r in qs:
        t-=1
        l-=1
        print(a[d][r] - a[d][l] - a[t][r] + a[t][l])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1