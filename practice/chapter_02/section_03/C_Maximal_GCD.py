import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

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
    n,k = list(map(int, input().split()))
    div = divisor(n)

    ans = -1

    for d in div:
        s = (d+d*k) * k //2
        if s <= n and (n-s) % d == 0:
            ans = max(d, ans)

    if ans == -1:
        print(ans)
    else:
        print(*[ans*(i+1) for i in range(k-1)] + [n - (ans+ans*(k-1))*(k-1)//2])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1