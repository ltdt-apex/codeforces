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
    n = int(input())
    
    adj = [[] for _ in range(n+1)]

    for _ in range(n-1):
        u,v = inputa()
        adj[u].append(v)
        adj[v].append(u)

    adj[1].append(-1)

    q = []
    q.append((-1,1,0,1))

    ans = 0

    while q:
        p,v,d,prob = q.pop()
        # print(p,v,d,prob)
        if len(adj[v]) == 1 and adj[v][0] == p:
            ans+=prob*d
        for u in adj[v]:
            if u == p:
                continue
            q.append((v,u,d+1,prob/max(1,len(adj[v])-1)))


    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)