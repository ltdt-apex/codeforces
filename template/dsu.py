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
    
dsu = DSU(5)
dsu.union(0,1)
dsu.union(1,2)
dsu.union(3,4)
dsu.union(1,2)
print(dsu.parent)
print(dsu.size)
print(dsu.group)
print(dsu.max_size)
print(dsu.same(0,1))
print(dsu.same(1,2))
print(dsu.same(0,4))