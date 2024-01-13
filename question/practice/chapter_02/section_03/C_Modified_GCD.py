import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math
import bisect

def divisor(n):
    """
    find all divisor of n
    O(sqrt(n))
    """
    import math

    half = int(math.sqrt(n)) + 1
    div = []
    for i in range(1, half):
        if n%i != 0:
            continue
        div.append(i)
        if i*i != n:
            div.append(n//i)

    return div

def solve():
    a,b = list(map(int, input().split()))
    n = int(input())

    diva = set(divisor(a))
    divb = set(divisor(b))

    div = diva & divb
    div = sorted(div)

    for i in range(n):
        l,r = list(map(int, input().split()))
        i = bisect.bisect_left(div, l)
        j = bisect.bisect_right(div, r)

        if i == len(div) or j == 0:
            print(-1)
            continue
        if div[j-1] < div[i]:
            print(-1)
            continue
        print(div[j-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1