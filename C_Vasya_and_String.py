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
    n,k = inputa()
    a = inputs()
    
    na, nb = 0,0
    l=0

    ans = 0
    for r in range(n):
        if a[r] == "a":
            na += 1
        else:
            nb += 1
        while na > k and nb > k:
            if a[l] == "a":
                na -=1
            else:
                nb -=1
            l+=1
        ans = max(ans, r-l+1)

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1