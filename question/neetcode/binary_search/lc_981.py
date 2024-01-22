from collections import defaultdict

class TimeMap:

    def __init__(self):
        self.d = defaultdict(list)
        self.dv = defaultdict(list)

    def set(self, key: str, value: str, timestamp: int) -> None:
        self.d[key].append(timestamp)
        self.dv[key].append(value)

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.d:
            return ""
        
        n = len(self.d[key])
        
        ans = -1
        i = n
        while i >=1:
            while ans+i<n and self.d[key][ans+i] <= timestamp:
                ans+=i
            i//=2

        return self.dv[key][ans] if ans!=-1 else ""


# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)