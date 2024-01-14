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
    a = [list(input().strip()) for i in range(n)]
    q = int(input())
    qs = [inputa() for i in range(q)]

    ap1 = [[0]*n for i in range(n)]
    ap2 = [[0]*n for i in range(n)]

    for i in range(n):
        for j in range(n):
            if a[i][j] == "O":
                ap1[i][j] += 1
                k = max(0,math.floor((j+2*m-n) / 2) + 1)
                if i + k < n:
                    # print(i,j,k)
                    ap2[i+k][j+2*m-2*k] -= 1
                if i+m < n:
                    ap1[i+m][j] -=1
                    ap2[i+m][j] +=1
    
    for i in range(1,n):
        for j in range(n):
            ap1[i][j] += ap1[i-1][j]
    # for i in range(n):
    #     print(*ap1[i])
    for i in range(1,n):
        for j in range(n-3,-1,-1):
            ap2[i][j] += ap2[i-1][j+2]
    # for i in range(n):
    #     print(*ap2[i])
    for i in range(n):
        for j in range(n):
            ap1[i][j] += ap2[i][j]

    # for i in range(n):
    #     print(*ap1[i])

    for i in range(n):
        for j in range(1,n):
            ap1[i][j] += ap1[i][j-1]

    for i,j in qs:
        print(ap1[i-1][j-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1