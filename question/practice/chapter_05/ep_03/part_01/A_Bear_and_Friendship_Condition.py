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

class DSU:
    def __init__(self, n):
        self.n = n
        
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]
        
        self.group = n
        self.max_size = 1
        
    def find(self, v):
        if v == self.parent[v]:
            return v
        
        self.parent[v] = self.find(self.parent[v])
        return self.parent[v]

    def union(self, u, v):
        u = self.find(u)
        v = self.find(v)
        
        if u != v:
            if self.size[u] > self.size[v]:
                u,v = v,u
            self.parent[u] = v
            self.size[v] += self.size[u]
            
            self.group -= 1
            self.max_size = max(self.max_size, self.size[v])
    
    def same(self, u, v):
        return self.find(u) == self.find(v)
    
def solve(test):
    n,m = inputa()

    dsu = DSU(n+1)
    adj = [[] for _ in range(n+1)]

    for _ in range(m):
        u,v = inputa()
        adj[u].append(v)
        adj[v].append(u)
        dsu.union(u,v)

    # print(dsu.size)

    for i in range(1,n+1):
        if dsu.size[dsu.find(i)] != len(adj[i])+1:
            print("NO")
            return
        
    print("YES")


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)