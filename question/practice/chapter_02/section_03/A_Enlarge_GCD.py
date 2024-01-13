import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def find_soe(n):
    """
    generate soe table from [0,n]
    O(nlog(log(n))) ~= O(n)

    log(log(n)) = 4.90... when n=10**9
    """
    soe = [0 for _ in range(n+1)]

    for i in range(4, n+1, 2):
        soe[i] = 2

    for i in range(3, n+1, 2):
        if soe[i]:
            continue
        for j in range(i*i, n+1, i*2):
            soe[j] = i
            j+=i*2

    return soe

soe = find_soe(int(1.5 * 10**7) + 1)

def factor(n):
    s =set()
    while soe[n] != 0:
        s.add(soe[n])
        n//=soe[n]

    if n > 1:
        s.add(n)

    return s


def solve():
    n = int(input())
    a = list(map(int, input().split()))

    gcd = math.gcd(*a)

    d = defaultdict(int)
    for num in a:
        num//=gcd
        s = factor(num)
        # print(s)
        for num in s:
            d[num] += 1
    # print(d)
    ans = n
    for v in d.values():
        ans = min(ans, n-v)
    print(ans if ans != n else -1)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1