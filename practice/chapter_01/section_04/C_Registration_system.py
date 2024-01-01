import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict


def solve():
    n = int(input())

    d = defaultdict(lambda: -1)
    for _ in range(n):
        s = input().strip()
        d[s] +=1
        if d[s] == 0:
            print("OK")
        else:
            print(s+str(d[s]))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1