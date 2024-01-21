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
    n = int(input())
    a = inputa()

    d = defaultdict(int)
    ans = math.inf

    for l in range(n):

        d2 = defaultdict(int)
        mr = l

        for r in range(l,n):
            if a[r] in d:
                mr = max(mr, r)
            if a[r] in d2:
                mr = max(mr, d2[a[r]])
            d2[a[r]] = r
        ans = min(ans, mr-l+1)

        d[a[l]] += 1
        if d[a[l]] == 2:
            break

    print(ans if (len(set(a)) != len(a)) else 0)
        

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1