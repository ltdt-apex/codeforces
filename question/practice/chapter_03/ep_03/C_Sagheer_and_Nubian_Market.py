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
    n,s = inputa()
    a = inputa()

    mm = 0

    ans = 0
    i = n
    while i >= 1:
        while ans + i <= n:
            j = ans+i
            ps = [p+(i+1)*j for i,p in enumerate(a)]
            ps.sort()
            p = sum(ps[:j])
            if p <= s:
                ans = j
                mm = p 
            else:
                break
        i//=2

    print(ans, mm)
    

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1