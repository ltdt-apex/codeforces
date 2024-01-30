import math

class Solution:
    def flowerGame(self, n: int, m: int) -> int:
        return math.ceil(n/2) * m //2 + math.ceil(m/2) * n //2