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
    n,m = inputa()
    
    adj = [[] for _ in range(n+1)]

    for _ in range(m):
        u,v = inputa()
        adj[u].append(v)
        adj[v].append(u)

    q = []
    color = [-1 for _ in range(n+1)] 

    for i in range(1,n+1):
        if color[i] == -1:
            q.append((i,0))

        while q:
            v,c = q.pop()
            if color[v] != -1:
                if color[v] != c:
                    print(f"Scenario #{test}:")
                    print(f"Suspicious bugs found!")
                    return
                
                continue

            color[v] = c

            for u in adj[v]:
                q.append((u,1-c))

    print(f"Scenario #{test}:")
    print(f"No suspicious bugs found!")

if __name__ == "__main__":
    test = 1
    test = int(input())
    c = 1
    while c <= test:
        solve(c)
        c+=1