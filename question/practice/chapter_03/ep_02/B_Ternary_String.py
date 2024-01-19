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
    a = inputs()
    a = list(map(int, a))

    cs = [0,0,0]
    ans = math.inf
    l=0
    
    for r in range(len(a)):
        cs[a[r] - 1] += 1
        while cs[a[l] - 1] > 1:
            cs[a[l]-1] -= 1
            l+=1
        if all(cs):
            ans = min(ans, r-l+1)

    print(ans if ans != math.inf else 0)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1