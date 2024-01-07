import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort(reverse=True)

    ans = []
    d = defaultdict(int)

    for num in a:
        if d[num] > 0:
            d[num] -= 1
            continue
        for num2 in ans:
            d[math.gcd(num, num2)] += 2

        ans.append(num)

        if len(ans) == n:
            break

    print(*ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1