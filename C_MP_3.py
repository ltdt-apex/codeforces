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
    n,I = inputa()
    a = inputa()
    a.sort()

    m = math.floor(2**(8*I/n))

    ans = 0
    l = 0
    for r in range(n):
        while a[r] - a[l] + 1 > m:
            l+=1
        
        ans = max(ans, r-l+1)
    
    print(n-ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1