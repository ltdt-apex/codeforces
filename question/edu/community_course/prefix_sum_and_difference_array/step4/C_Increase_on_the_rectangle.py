import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def prefix_2d(a):
    from itertools import accumulate
    
    return list(list(a) for a in zip(*map(accumulate, zip(*map(accumulate, a)))))

def inputa():
    return list(map(int, input().split()))

def solve():
    n,m = inputa()
    a = [inputa() for i in range(n)]

    q = int(input())
    qs = [inputa() for i in range(q)]

    ap = [[0]*m for i in range(n)]
    for x,y,xx,yy,d in qs:
        x-=1
        y-=1
        ap[x][y]+=d
        if xx < n:
            ap[xx][y]-=d
        if yy<m:
            ap[x][yy]-=d
        if xx < n and yy < m:
            ap[xx][yy]+=d
    
    ap = prefix_2d(ap)

    for i in range(n):
        for j in range(m):
            a[i][j] += ap[i][j]
        print(*a[i])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1