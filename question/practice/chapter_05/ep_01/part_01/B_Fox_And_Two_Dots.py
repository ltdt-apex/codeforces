import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def inputs():
    return list(input().strip())

dir = [(-1,0),(1,0),(0,-1),(0,1)]

def solve(test):
    n,m = inputa()
    g = [inputs() for _ in range(n)]

    q = []
    seen = set()

    for i in range(n):
        for j in range(m):
            if (i,j) not in seen:
                q.append((-1,-1,i,j))

                while q:
                    pi,pj,ii,jj = q.pop()
                    seen.add((ii,jj))

                    for di,dj in dir:
                        ni = ii + di
                        nj = jj + dj
                        if ni < 0 or ni >=n or nj < 0 or nj>=m or (ni,nj)==(pi,pj) or g[ii][jj] != g[ni][nj]:
                            continue

                        if (ni,nj) in seen:
                            # print(ni,nj)
                            print("Yes")
                            return
                        q.append((ii,jj,ni,nj))
    
    print("No")
                        
                        

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)