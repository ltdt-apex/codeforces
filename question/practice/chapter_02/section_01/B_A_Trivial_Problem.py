import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    n = int(input())
    d = defaultdict(int)

    i = 1
    ans = set()
    while True:
        i += 1
        cur = i
        while cur%2==0:
            d[2] += 1
            cur//=2
        while cur%5==0:
            d[5] += 1
            cur//=5
        m = min(d[2], d[5])
        if m == n:
            ans.add(i)
        if m > n:
            break
    # print(m)

    print(len(ans))
    for n in ans:
        print(n, end=" ")

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1