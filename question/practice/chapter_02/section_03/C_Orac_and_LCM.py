import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    p = [0]
    s = [0]

    for i in range(n):
        p.append(math.gcd(p[-1], a[i]))

    for i in range(n-1, -1, -1):
        s.append(math.gcd(s[-1], a[i]))

    ans = []
    for i in range(n):
        ans.append(math.gcd(p[i], s[n-1-i]))

    # print(ans)

    print(math.lcm(*ans))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1