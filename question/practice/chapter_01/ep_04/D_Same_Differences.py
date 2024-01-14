import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0
    d = defaultdict(int)
    for i, num in enumerate(a):
        diff = num-i
        ans += d[diff]
        d[diff] += 1
    print(ans) 


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1