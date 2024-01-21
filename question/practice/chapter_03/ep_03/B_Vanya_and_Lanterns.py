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
    n,l = inputa()
    a = inputa()

    a.sort()

    ans = 0
    for i in range(1, len(a)):
        ans = max((a[i]-a[i-1])/2, ans)

    print(max(ans,a[0],l-a[-1]))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1