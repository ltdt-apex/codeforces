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
    a,b = list(map(int, input().split()))
    if a==b:
        print(0)
        return

    if a>b:
        a,b = b,a
    
    n = b-a
    div = divisor(n)
    ans = (math.inf, math.inf)
    for d in div:
        q = math.ceil(a/d)
        k = d*q-a

        lcm = ((a+k)*(b+k)//math.gcd(a+k, b+k))
        if lcm < ans[0] or lcm == ans[0] and k < ans[1]:
            ans = (lcm, k)

    print(ans[1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1