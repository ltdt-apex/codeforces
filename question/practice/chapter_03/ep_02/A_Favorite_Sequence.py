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

    l = 0 
    r = n-1
    alt = 1
    ans = []
    while l<=r:
        if alt == 1:
            ans.append(a[l])
            l+=1
        else:
            ans.append(a[r])
            r-=1
        alt = 1-alt
    print(*ans)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1