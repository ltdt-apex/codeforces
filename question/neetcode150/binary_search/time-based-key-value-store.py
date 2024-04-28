from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.d = defaultdict(list)
        

    def set(self, k: str, v: str, t: int) -> None:
        self.d[k].append((v,t))
        

    def get(self, k: str, t: int) -> str:
        a = self.d[k]

        i = 0
        n = len(a)
        while n:
            while i + n < len(a) and a[i+n][1] <= t:
                i+=n
            n//=2

        return a[i][0] if a[i][1] <= t else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)