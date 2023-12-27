import sys
sys.setrecursionlimit(10**5+5)
# input = sys.stdin.readline
from collections import Counter

def solve():
    _, n = list(map(int, input().split()))
    s = input().strip()

    c = Counter(s)
    for i in range(26):
        l = chr(i+ord("a"))
        if n <= c[l]:
            c[l] -= n
            break
        n-=c[l]
        c[l] = 0
    ns = []
    for l in (s[::-1]):
        if c[l] > 0:
            c[l]-=1
            ns.append(l)
    ns = "".join(list(reversed(ns)))
    print(ns)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1