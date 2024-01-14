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

ps = phi_1_to_n(10**7)
ps = list(accumulate(ps))

def solve():
    l,r = list(map(int, input().split()))

    print(ps[r] - ps[l-1])

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1