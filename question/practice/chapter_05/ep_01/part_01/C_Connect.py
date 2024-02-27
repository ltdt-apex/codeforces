import sys
sys.setrecursionlimit(10**5+5)
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
    n = int(input())
    s = inputa()
    t = inputa()
    m = [inputs() for _ in range(n)]

    seen_s = set()
    seen_t = set()

    def dfs(i,j,seen):
        if (i,j) in seen:
            return
        seen.add((i,j))

        for di,dj in dir:
            ni = i+di
            nj = j+dj
            if ni < 0 or ni >=n or nj<0 or nj>=n or m[ni][nj] == "1":
                continue
            dfs(ni, nj, seen)

    dfs(s[0]-1,s[1]-1,seen_s)
    dfs(t[0]-1,t[1]-1,seen_t)

    # print(seen_s)
    # print(seen_t)

    ans = math.inf
    for (si, sj) in seen_s:
        for (ti, tj) in seen_t:
            ans = min(ans, (si-ti)**2 + (sj-tj)**2)

    print(ans)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        test-=1
        solve(test)