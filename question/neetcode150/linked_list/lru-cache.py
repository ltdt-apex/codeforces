class LRUCache:

    def __init__(self, c: int):
        self.d = dict()
        self.c = c
        self.r = -1

    def get(self, k: int) -> int:
        if k in self.d:
            self.r = k
            return self.d[k]
        return -1

    def put(self, k: int, v: int) -> None:
        if len(self.d) == self.c:
            del[self.d[self.r]]
        self.d[k] = v


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)