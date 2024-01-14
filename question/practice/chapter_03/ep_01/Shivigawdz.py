import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,d,c = inputa()
    a = inputa()
    a = [0] + list(accumulate(a))

    ans = 0
    for i in range(1,n+1):
        for j in range(c,d+1):
            if i+j-1 >= n+1:
                break
            ans = max(ans, (a[i+j-1] - a[i-1])/j)

    print(ans)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1