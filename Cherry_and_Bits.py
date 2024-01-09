import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m = inputa()
    a = [[int(c) for c in input().strip()] for i in range(n)]

    q = int(input())
    qs = [inputa() for i in range(q)]

    ap = [[0]*(m+2) for _ in range(n+2)]

    for t,l,d,r in qs:
        ap[t][l]+=1
        ap[t][r+1]-=1
        ap[d+1][l]-=1
        ap[d+1][r+1]+=1
    
    for i in range(1,n+1):
        for j in range(1, m+1):
            ap[i][j] += ap[i-1][j] + ap[i][j-1] - ap[i-1][j-1]
            
    for i in range(1,n+1):
        for j in range(1,m+1):
            a[i-1][j-1] += ap[i][j]
            a[i-1][j-1] %= 2

    for i in range(n):
        for j in range(m):
            print(a[i][j], end="")
        print()


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1