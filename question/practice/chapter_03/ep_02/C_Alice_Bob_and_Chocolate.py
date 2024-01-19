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
    ans = [0,0]
    t = [0,0]
    while l<=r:
        if t[0] <= t[1]:
            t[0]+=a[l]
            ans[0]+=1
            l+=1
        else:
            t[1]+=a[r]
            ans[1]+=1
            r-=1
    
    print(*ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1