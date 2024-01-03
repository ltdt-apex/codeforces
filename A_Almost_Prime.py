import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math
 
# def plain_factor(n):
#     d = defaultdict(int)
 
#     i = 2
#     while i*i <= n:
#         while n%i == 0:
#             d[i] += 1
#             n//=i
#         i+=1
    
#     if n > 1:
#         d[n] += 1
#     return d
 
def plain_factor(n):
    s = set()
 
    i = 2
    while i*i <= n:
        while n%i == 0:
            n//=i
            s.add(i)
        i+=1
    
    if n>1:
        s.add(n)
    return s
 
def solve():
    n = int(input())
    ans = 0
    for i in range(1,n+1):
        s = plain_factor(i)
        a = len(s)
        if a == 2:
            ans += 1
 
    print(ans)
 
if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1


        