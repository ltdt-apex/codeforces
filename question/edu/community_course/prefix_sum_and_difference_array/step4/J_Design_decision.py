import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m,k = inputa()
    a = inputa()

    if k <= m:
        print(10**6-k+1)
        return

    cur = 1
    a = list(set(a))
    a.sort()
    # print(a)

    ans = 0

    for i in range(n):
        l = i
        r = i + k-m-1
        if r >= n:
            break
        if a[r] - a[l] + 1 > k:
            continue
        r1 = max(cur, a[r] - k + 1)
        r2 = max(a[l],cur)
        cur = r2 + 1
        # print(i,l,r,r1,r2, a[r]-a[l]+1)

        ans += r2-r1+1
        if r2 + k - 1 > 10**6:
            ans-= min(r2 + k - 1 - 10**6, r2-r1+1)
            break
        # print(i, ans)

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1