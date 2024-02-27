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

def solve(test):
    n, k = inputa()
    a = [0] + inputa()

    adj = [[] for _ in range(n+1)]

    for _ in range(n-1):
        u,v = inputa()
        adj[u].append(v)
        adj[v].append(u)

    q = []

    q.append((-1,1,a[1]))

    ans = 0
    while q:
        p,v,c = q.pop()
        # print(p,v,c)
        if c > k:
            continue
        if len(adj[v]) == 1 and adj[v][0] == p:
            ans+=1

        for u in adj[v]:
            if u == p:
                continue
            if a[u] == 0:
                nc = 0
            else:
                nc = c+1
            q.append((v,u,nc))

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)