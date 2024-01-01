import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    n = int(input())
    a = input().strip()

    ans = 0

    d = defaultdict(int)
    for i, c in enumerate(a):
        if i %2:
            if d[c] == 0:
                ans+=1
            else:
                d[c]-=1
        else:
            c = c.upper()
            d[c] += 1

    print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1