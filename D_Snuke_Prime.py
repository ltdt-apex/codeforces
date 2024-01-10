import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,c = inputa()
    ns = [inputa() for i in range(n)]

    s = set()
    for l,r,v in ns:
        s.add(l)
        s.add(r+1)

    s = sorted(s)
    d = {v:i for i,v in enumerate(s)}

    a = [0]*len(s)

    for l,r,v in ns:
        a[d[l]] += v
        a[d[r+1]] -= v
    
    a = list(accumulate(a))

    ans = 0
    for i in range(len(s)-1):
        ans += min(a[i], c) * (s[i+1] - s[i])

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1