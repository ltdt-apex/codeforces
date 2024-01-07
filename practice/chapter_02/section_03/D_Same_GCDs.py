import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def phi(n):
    p = n
    i = 2
    while i * i <= n:
        if n%i == 0:
            while n%i == 0:
                n//=i
            p -= p//i
        i+=1
    
    if n > 1:
        p-=p//n

    return p

def solve():
    # n = int(input())
    a,b = list(map(int, input().split()))

    n = math.gcd(a,b)

    b//=n
    print(phi(b))

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1