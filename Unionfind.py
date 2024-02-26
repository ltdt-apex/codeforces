import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

class DSU:
    def __init__(self, n):
        self.n = n
        
        self.parent = [i for i in range(n)]
        self.size = [1 for _ in range(n)]
        
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
    
    def same(self, u, v):
        return self.find(u) == self.find(v)
    
    @property
    def n_group(self):
        parents = set()
        for i in range(self.n):
            parents.add(self.find(i))
        
        return len(parents)

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

def solve(test):
    n,q = inputa()

    dsu = DSU(n)
    for _ in range(q):
        t,u,v = inputa()
        if t:
            print(int(dsu.same(u,v)))
        else:
            dsu.union(u,v)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)