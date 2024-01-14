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

    t = [0,0]

    for i in range(1,n):
        t[1-i%2] += a[i]

    ans = 0
    if t[0] == t[1]:
        ans = 1

    for i in range(1,n):
        if i%2:
            t[0]-=a[i]
            t[0]+=a[i-1]
        else:
            t[1]-=a[i]
            t[1]+=a[i-1]

        if t[0] == t[1]:
            ans+=1
    print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1