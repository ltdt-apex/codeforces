import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n,k = inputa()
    a = [list(input().strip()) for i in range(n)]

    apr = [0]*n
    apc = [0]*n

    for i in range(n):
        for j in range(n):
            if a[i][j] == "W":
                apr[i] += 1
                apc[j] += 1

    complete = 0
    for i in range(n):
        if apr[i] == n:
            complete += 1
        if apc[i] == n:
            complete += 1

    nn = n-k+1


    b = [[0]*(n) for i in range(nn)]

    for j in range(n):
        c = 0
        for i in range(n):
            if a[i][j] == "B":
                c += 1
            l = i-k
            if l >= 0 and a[l][j] == "B":
                c -= 1
            if i>=k-1:
                b[i-k+1][j] = c

    for j in range(n):
        for i in range(nn):
            if b[i][j] + apc[j] == n and apc[j] != n:
                b[i][j] = 1
            else:
                b[i][j] = 0

    bcc = [[0]*nn for i in range(nn)]

    for i in range(nn):
        c = 0
        for j in range(n):
            c += b[i][j]
            l = j-k
            if l >= 0:
                c-=b[i][l]
            if j>=k-1:
                bcc[i][j-k+1] += c

    b = [[0]*(nn) for i in range(n)]

    for i in range(n):
        c = 0
        for j in range(n):
            if a[i][j] == "B":
                c += 1
            l = j-k
            if l >= 0 and a[i][l] == "B":
                c -= 1
            if j>=k-1:
                b[i][j-k+1] = c

    for i in range(n):
        for j in range(nn):
            b[i][j] = 1 if b[i][j] + apr[i] == n and apr[i] != n else 0

    for j in range(nn):
        c = 0
        for i in range(n):
            c += b[i][j]
            l = i-k
            if l >= 0:
                c-=b[l][j]
            if i>=k-1:
                bcc[i-k+1][j] += c

    ans = 0
    for i in range(nn):
        for j in range(nn):
            ans = max(ans, bcc[i][j])

    print(complete+ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1