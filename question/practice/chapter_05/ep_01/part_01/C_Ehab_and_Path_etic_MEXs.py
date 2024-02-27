import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math
from collections import defaultdict

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n = int(input())

    e = [inputa() for _ in range(n-1)]

    d = defaultdict(int)
    c3 = None
    for u,v in e:
        d[u] += 1
        d[v] += 1
        if d[u] == 3:
            c3 = u
            break
        if d[v] == 3:
            c3 = v
            break

    if c3 is None:
        for i in range(n-1):
            print(i)
        return
    
    c = 0
    ans = [-1 for _ in range(n-1)]
    for i, (u,v) in enumerate(e):
        if u==c3 or v == c3:
            ans[i] = c
            c+=1

    for i in range(n-1):
        if ans[i] == -1:
            ans[i] = c
            c+=1

    for x in ans:
        print(x)



if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)