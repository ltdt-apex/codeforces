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
            color[v] = c
            for u in adj[v]:
                if color[u] != -1:
                    if color[u] != 1-c:
                        print(-1)
                        return 
                else:
                    q.append((u,1-c))

    ans0 = [i for i in range(1,n+1) if color[i]==0]
    ans1 = [i for i in range(1,n+1) if color[i]==1]

    print(len(ans0))
    print(*ans0)
    print(len(ans1))
    print(*ans1)
                


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)