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

def work(a, d):
    w = 0
    for i in range(len(a)):
        w+=max(0, a[i] - i//d)

    return w

def solve():
    n,m = inputa()
    a = inputa()

    a.sort(reverse=True)

    ans = 0
    i = n
    while i >= 1:
        while ans + i <= n and work(a, ans + i) < m:
            ans+=i
        i//=2 

    print(ans+1 if ans!=n else -1)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1