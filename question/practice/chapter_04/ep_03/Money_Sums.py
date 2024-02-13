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

    ans = [1] + [0]*(sum(a))

    for v in a:
        for j in range(len(ans)-1,-1,-1):
            if j-v>=0:
                ans[j] |= ans[j-v]

    ans = [i for i in range(1,len(ans)) if ans[i] == 1]

    print(len(ans))
    print(*ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1