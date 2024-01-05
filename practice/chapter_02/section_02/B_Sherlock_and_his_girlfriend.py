import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def is_prime(n):
    if n < 2:
        return False
    
    i = 2
    while i*i <= n:
        if n%i == 0:
            return False
        i+=1
        
    return True

def solve():
    n = int(input())

    print(1 if n < 3 else 2)

    for i in range(2,n+2):
        print(1 if is_prime(i) else 2, end=" ")
    
if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1