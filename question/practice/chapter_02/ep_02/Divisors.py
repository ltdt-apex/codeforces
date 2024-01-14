from functools import reduce
import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

# def find_soe(n):
#     soe = [0 for _ in range(n+1)]

#     for i in range(2, n+1):
#         if soe[i] != 0:
#             continue
#         j = i*2
#         while j < n+1:
#             soe[j] = i
#             j+=i

#     return soe

def find_n_divisor(n):
    div = [0 for _ in range(n+1)]

    for i in range(1, n+1):
        j = i
        while j < n+1:
            div[j]+=1
            j+=i

    return div

div = find_n_divisor(10**6)

def find_soe(n):
    soe = [[] for _ in range(n+1)]

    for i in range(2, n+1):
        if soe[i]:
            continue
        j = i*2
        while j < n+1:
            soe[j].append(i)
            j+=i

    return soe

soe = find_soe(10**6)

# print(soe[:20])

# def factor_soe(n):
#     d = defaultdict(int)
#     while soe[n] != 0:
#         d[soe[n]]+=1
#         n//=soe[n]
#     if n > 1:
#         d[n] += 1
#     return d

# def find_dn(d):
#     # return math.prod(v+1 for v in d.values())
#     return reduce(lambda x,y: x*y, [v+1 for v in d.values()], 1)

def solve():
    count = 0
    # for i in range(1, 20):
    for i in range(1, 10**6+1):
        if len(soe[div[i]]) == 2:
            count += 1
        if count == 9:
            count = 0
            print(i)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1