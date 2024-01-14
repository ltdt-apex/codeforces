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
    b = a.copy()
    b.sort()
    b = [0]+list(accumulate(b))
    a = [0]+list(accumulate(a))

    q = int(input())
    for i in range(q):
        t,l,r = inputa()
        l-=1
        if t==1:
            print(a[r]-a[l])
        else:
            print(b[r]-b[l])



if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1