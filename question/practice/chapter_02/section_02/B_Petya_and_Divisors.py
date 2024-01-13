import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def divisor(n):
    """
    find all divisor of n
    O(sqrt(n))
    """
    h = int(math.sqrt(n)) + 1
    div = []
    for i in range(1,h):
        if n%i==0:
            div.append(i)
            div.append(n//i)

    return div

def solve():
    n = int(input())
    last = [-1 for _ in range(10**5+1)]
    for i in range(n):
        x, j = list(map(int, input().split()))
        div = divisor(x)
        t = i-j
        count = 0
        for d in div:
            # print(d)
            if last[d] < t:
                count += 1
            last[d] = i
        print(count)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1