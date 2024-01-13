import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,q = inputa()

    a = inputa()
    qs = [inputa() for i in range(q)]

    qp = [0] * n

    for l,r in qs:
        l-=1
        qp[l] += 1
        if r < n:
            qp[r] -= 1
    
    qp = list(accumulate(qp))

    a.sort()
    qp.sort()

    print(sum(i*j for i,j in zip(a,qp)))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1