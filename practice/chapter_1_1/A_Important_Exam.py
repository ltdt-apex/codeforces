import sys
sys.setrecursionlimit(10**5+5)
from collections import defaultdict
input = sys.stdin.readline

def solve():
    n,m = list(map(int, input().split()))

    a = [input() for i in range(n)]
    s = list(map(int, input().split()))

    ans = 0
    for i in range(m):
        d = defaultdict(int)
        for j in range(n):
            d[a[j][i]] += 1
        ans += max(d.values()) * s[i]

    print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1