import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
from itertools import accumulate
import math

def inputa():
    return list(map(int, input().split()))

def solve():
    n = int(input())
    a = inputa()

    p = []
    last = 0
    for i in range(n):
        if a[i] != a[last]:
            p.append(i-last)
            last = i

    p.append(n-last)

    ans = []
    ans.append(p[0])

    cur = 0
    for i in range(1,len(p)):
        cur += p[i]
        if cur > ans[0]:
            ans.append(cur)
            last = i+1
            break
    
    if len(ans) == 1:
        print(0,0,0)
        return
    
    cur = 0
    for i in range(last,len(p)):
        cur += p[i]
        if ans[0] + ans[1] + cur > n//2:
            cur -= p[i]
            break

    if cur==0 or cur <= ans[0]:
        print(0,0,0)
    else:
        ans.append(cur)
        print(*ans)
    

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1