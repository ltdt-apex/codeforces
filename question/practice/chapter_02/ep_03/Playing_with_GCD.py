import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def phi_1_to_n(n):
    phis = [i for i in range(n+1)]

    for i in range(2, n+1, 2):
        phis[i] -= phis[i]//2

    for i in range(3, n+1, 2):
        if phis[i] == i:
            for j in range(i, n+1, i):
                phis[j] -= phis[j]//i
    
    return phis

ps = phi_1_to_n(10**5)
ps = [i - ps[i] for i in range(len(ps))]
ps = list(accumulate(ps))

def solve(i):
    a = int(input())
    print(f"Case {i}: {ps[a]}")


if __name__ == "__main__":
    test = 1
    test = int(input())
    for i in range(1, test+1):
        solve(i)
        test-=1