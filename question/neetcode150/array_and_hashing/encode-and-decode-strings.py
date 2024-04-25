from typing import List

class Solution:

    def encode(self, ss: List[str]) -> str:
        a = ""
        for s in ss:
            a += str(len(s)) + "#" + s

        return a

    def decode(self, ss: str) -> List[str]:
        a = []

        i = 0
        while i < len(ss):
            n = ""
            while ss[i] != "#":
                n+=ss[i]
                i+=1
            i+=1
            a.append(ss[i:i+int(n)])
            i+=int(n)

        return a